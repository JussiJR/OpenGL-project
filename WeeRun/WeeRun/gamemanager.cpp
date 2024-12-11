#include "gamemanager.h"

GameManager::GameManager(const char* path)
{
	//!		Ínitialized
	Initialized = Exceptions_Null;
	
	_chunkOffsets = new int[32];
	_chunkSizes = new int[32];

	//!		Player state
	_haunted = 0;

	//!		Game settings
	_difficulty = 0;
	_gameMode = 0;

	//!		Counters
	_unixTimer = 0;
	_entityCount = 1;
	

	//!		Initialize Pool
	_entitys = Pool<Entity>(10, true);
	
	//!		Initialize Player
	{
		Entity plr = Entity(1, 0, 0); // may cause some undefined actions since it gets yeeted from stack soon
		_entitys.Add(&plr);
	}
	//!		Initialize Camera	
	_camera = Camera(_entitys[0],glm::vec3(0.0f,3.0f,0.0f));




	//!		Initialize OpenGL objects	
	{


		//!		Get root
		Json::Value root(0);
		getRoot(&root, path, &Initialized);
		if (Initialized) return;
		
		//!	Initialize Shader program
		_shader = ShaderProgram("vertex.vert", "fragment.frag", (int*) & Initialized);
		if (Initialized) return;
		_shader.Activate();

		//! Initializee vap. vbo amd ubo
		{
			_vertexArray = VAO();
			_vertexArray.Bind();

			const float vYs[4] = { 0.0f,0.0f,9.0f,9.0f };
			_vertexbuffer = VBO((void*)&vYs[0], 4 * sizeof(float)); //just do not complain
			_vertexArray.LinkAttrib(_vertexbuffer, 0, 4, GL_FLOAT, 4, (void*)0);

			const int uboPrefill[15]{ 0 };
			_edgeData = UBO(sizeof(int) * 15,(void*) & uboPrefill[0], GL_DYNAMIC_DRAW);//just do not complain
		}
	

		//!		Map initialization
		{
			//!		Get buffer length
			int i = 0, j = 0,k = 0;
			getBufferLength(&root, &Initialized, &i, &j, _chunkSizes, _chunkOffsets);
			if (Initialized) return;

			//!		Create buffer
			fillBuffer(_mapBuffer, &root, &Initialized);
			if (Initialized) return;
		}

		{
			//!		Calculate projection matrix
			GLint projectionUniform = _shader.getUniform("u_projection ");
			if (projectionUniform == -1) {
				Initialized = Shader_ShaderProgram_ShaderUniform_NotFound_Exception;
				return;
			}

			//!		Set projection matrix and never touch again
			glm::mat4 projection = glm::perspective(90.0f, Aspect_Ratio, 0.75f, 100.0f);
			glUniformMatrix4fv(projectionUniform, 1, GL_FALSE, glm::value_ptr(projection));
		}

	}
}

GameManager::~GameManager()
{
	//! Delete rendering stuff
	_vertexbuffer.Delete();
	_edgeData.UnMap();
	_vertexArray.Delete();
	_shader.Delete();


}

int GameManager::Update(int* errorc)
{
	//!	Update camera 
	_camera.Update(0.f,0.f);



	return *errorc;
	return EXIT_SUCCESS;
}

int GameManager::FixedUpdate(int* errorc)
{

	return *errorc;
	return EXIT_SUCCESS;
}

int GameManager::Render(int* errorc, int render_distance)
{
	// |PlaceHolder | ChunkStart|
	int j = -1, k = 0;

	//! Retrieve camera position
	
	glm::vec2 camera_position = _camera.Assigned->Position;
	glm::vec3 camera_rotation = _camera.Rotation;

	// Buffer for data
	int buffer[500] { 0 }; // just run over it
	{
		//!	RENDER Wall
		
		//FIXME:  MANY MEMORY LOSS SPOT
		queue<int> _queue = queue<int>();
		unsigned long chunk,bufferoffset,link = -1, current = -1;
		unsigned long last[2]{ 0 };
		
		// Current Edge data
		float angle,yawOffset = camera_rotation.x;

		//!	Loop threw camera view
		_queue.push(_camera.Assigned->CurrentChunk);
		while (!_queue.empty()) {
			//!		Get chunk data
			chunk = _queue.front();
			_queue.pop();
			bufferoffset = _chunkOffsets[chunk];

			//! Set StartIndex
			k = j;

			//!		Loop chunk
			for (int i = 0;i < _chunkSizes[chunk];i++) {

				//!		Get edge data
				int index = link == -1 ? i : link;
				edge _edge = _mapBuffer[bufferoffset + index];


				//!		Calculate Direction in 2D space
				glm::vec2 direction = _edge.Position() - camera_position;

				//!	Calculate angle
				angle = atan2f(direction.y, direction.x);
				angle += angle < 0 ? 6.28318530718f : 0.0f;

				//!	Check is it in view
				int view = angle < fov + yawOffset && angle > yawOffset;

				//!	Add possible portal link to render pile and skip the edge adding (to reduce vertex amount)
				if (_edge.PortalLinkChunkIndex != chunk) _queue.push(_edge.PortalLinkChunkIndex);

				if (view || last[1]) 
				{
					//Pack 
					current = _edge.pack();

					//!	Add items into buffer	
					buffer[++j] = last[0];
					buffer[++j] = current;
				}

				//Set last
				last[0] = current;
				last[1] = view;
			}
		}
	}
	
	//!	Get actual count
	unsigned int count = (j+1) >> 1;// Kinda cheap way to divide by 2.

	//! Set Render Data
	_edgeData.Update(sizeof(int) * j, 0, buffer);
	//!	Calculate mvp matrix
	glm::mat4 view = glm::lookAt(
		glm::vec3(camera_position.x, 1.81f, camera_position.y),			// Position
		camera_rotation,												// Rotation
		glm::vec3(0, 0, 1));											// Up
	
	
	//!	Get uniform
	GLint viewUniform = _shader.getUniform("u_view");
	if (viewUniform == -1) {
		*errorc = 200;
		return EXIT_FAILURE;
	}

	return viewUniform;

	//!	Set mvp matrix uniform
	glUniformMatrix4fv(viewUniform, 1, GL_FALSE, glm::value_ptr(view));

	//! Draw everything in one batch
	glDrawElementsInstanced(GL_TRIANGLE_STRIP, 4, GL_FLOAT, 0, count);
	return EXIT_SUCCESS;
}


inline void getBufferLength(Json::Value* root,unsigned int* error, int* edgecount, int* chunkCount, int* _chunkSizes, int* _chunkOffsets)
{
	
	Json::Value::ArrayIndex i = 0;
	Json::Value chunkOffsets;
	Json::Value chunkSizes;
	if (!isValid(root, &chunkOffsets, "chunkOffsets")) *error = Map_BrokenMap_Exception;
	while (i < chunkOffsets.size() && chunkOffsets[i].asInt() != 0) {
		int j = chunkOffsets[i].asInt();
		*edgecount += j;
		_chunkOffsets[i] = *edgecount;
		_chunkSizes[i] = j;
		i++;
	}
	if (!*edgecount) *error = Map_InvalidMapExtension_Exception;
	*chunkCount = i;
}

inline void fillBuffer(edge* buffer, Json::Value* root, unsigned int* error){
	Json::Value Chunks; 
	int buffer_i = 0, edge_data;
	map<int, glm::vec2> offsetBinder;
	if (!isValid(root, &Chunks, "chunks")) {*error = MapTree_InvalidMap_Excecution;return;}
	for (Json::Value::ArrayIndex i = 0;i < Chunks.size();i++) {
		Json::Value Edges;
		if (!isValid(&Chunks[i], &Edges, "edges")) { *error = MapTree_InvalidMap_Excecution;return; }
		for (Json::Value::ArrayIndex j = 0;j < Edges.size();j++) {
			edge_data = Edges[j].asInt();

			//! Exctract the edge and apply offset
			int link = (edge_data >> 28) & 0xF;
			int texture = (edge_data >> 24) & 0xF;
			int x = ((edge_data >> 17) & 0x7F);
			int y = ((edge_data >> 10) & 0x7F);
			int portalLink = (edge_data >> 6) & 0x1F;
			int portalChunkIndex = edge_data & 0x3F;
			buffer[buffer_i++] = edge(link,texture,x,y,portalLink,portalChunkIndex);
		}
	}
}

void getRoot(Json::Value* root,const char* path, unsigned int* error) {
	Json::CharReaderBuilder builder;
	std::string errs;
	//? create stream
	std::ifstream s(path);
	s >> *root;
}

inline bool isValid(Json::Value* root,Json::Value* target,const char* name) {
	*target = root->get(name, NULL);
	return *target != NULL;
}