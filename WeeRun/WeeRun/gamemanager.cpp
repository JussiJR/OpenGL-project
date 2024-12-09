#include "gamemanager.h"

GameManager::GameManager(const char* path)
{
	//!		Ínitialized
	Initialized = 0;

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
	_camera = Camera(_entitys[0], vec2(1.3f, 12.3f));




	//!		Initialize OpenGL objects	
	{


		//!		Get root
		Json::Value root(0);
		getRoot(&root, path, &Initialized);
		if (Initialized) return;
		
		_shader = ShaderProgram("vertex.vert", "fragment.frag");
		_shader.Activate();

		//!		Map initialization
		{
			//!		Get buffer length
			int i = 0, j = 0,k = 0;
			getBufferLength(&root, &Initialized, &i, &j, _chunkSizes, _chunkOffsets);
			if (Initialized) return;

			//!		Create buffer
			_mapBuffer = new int[i];
			fillBuffer(_mapBuffer, &root, &Initialized);

			//!		Setup SSBOs
			_edgeData = SSBO(i, _mapBuffer, GL_DYNAMIC_STORAGE_BIT, 0);
			
		}

		//! Get uniforms
		_mvpUniform = glGetUniformLocation(_shader.ID, "u_mvp");

	}
}

GameManager::~GameManager()
{
	//! Delete rendering stuff
	_vertexArray.Delete();
	_indices.Delete();
	_shader.Delete();

	delete[] _mapBuffer;
}

int GameManager::Update(int* errorc)
{

	///!	Update camera 
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

	// Buffer for data
	int buffer[500] { 0 };
	{
		//!	RENDER Wall
		
		//FIXME:  MANY MEMORY LOSS SPOT
		queue<int> _queue = queue<int>();
		unsigned long chunk, edge,bufferoffset;
		unsigned long last[2]{ 0 };
		
		// Current Edge data
		int link = 0, texture, x, y, portalLink, portalChunkIndex;
		float angle,yawOffset = _camera.GetRotation().x;
		vec2 camera_position = _camera.getPointed()->Position;

		//!	Loop threw camera view
		_queue.push(_camera.getPointed()->CurrentChunk);
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
				edge = _mapBuffer[bufferoffset + link];
				extractEdge(edge, &link, &texture, &x, &y, &portalLink, &portalChunkIndex);


				//!		Calculate Direction in 2D space
				vec2 direction = vec2(x, y) - camera_position;

				//!	Calculate angle
				angle = atan2f(direction.y, direction.x);
				angle += angle < 0 ? 6.28318530718f : 0.0f;
				int view = inView(angle, yawOffset);
			
			

				//!	Check is it in view
				if (view || last[1]) 
				{

					//!	Add possible portal link to render pile and skip the edge adding (to reduce vertex amount)
					if (portalChunkIndex != chunk) 
					{
						//!	Push to queue portal
						_queue.push(portalChunkIndex);
					}
					else // Or add pair to renderable pile
					{
						//!	Add items into buffer	
						buffer[++j] = last[0];
						buffer[++j] = edge;
					}
				
				}

				//! Setup last
				last[0] = edge;
				last[1] = view;
			}

			//Close the chunk
			buffer[k] = buffer[j];
		}
	}
	// Kinda cheap way to divide by 2.
	unsigned int count = (j+1) >> 1;

	// Set Render Data
	_edgeData.Update(sizeof(int) * j, 0, *buffer);

	/*TODO: Calculate mvp*/
	

	//! Draw everything in one batch
	glDrawElementsInstanced(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, 0, count);
	return EXIT_SUCCESS;
}



inline string readFile(const char* path,unsigned int* error) {
	FILE* fileptr;
	fopen_s(&fileptr,path, "r");
#if defined(_DEBUG)
	if (!fileptr) {
		throw(errno);
		return "";
	}
#else
	if (!fileptr) {
		*error = EXCEPTION_GAMEMANAGER_INITIALIZATION_MAPNOTFOUND;
		return "";
	}
#endif

	//			Kinda like evil bit troll but not
	char buffer[100];
	int i = 0,size = 100;
	string ret = "";
	while (fgets(buffer,size, fileptr)) {	
		ret += buffer;
	}
	fclose(fileptr);
	return ret;
}

inline void getBufferLength(Json::Value* root,unsigned int* error, int* edgecount, int* chunkCount, int _chunkSizes[63], int _chunkOffsets[63])
{
	
	Json::Value::ArrayIndex i = 0;
	Json::Value chunkOffsets;
	Json::Value chunkSizes;
	if (!isValid(root,&chunkOffsets,"chunkOffsets")) * error = EXCEPTION_GAMEMANAGER_INITIALIZATION_INVALID_MAP_TREE;
	while (i < chunkOffsets.size() && chunkOffsets[i].asInt() != 0) {
		int j = chunkOffsets[i].asInt();
		*edgecount += j;
		_chunkOffsets[i] = *edgecount;
		_chunkSizes[i] = j;
		i++;
	}
	if (!*edgecount) *error = EXCEPTION_GAMEMANAGER_INITIALIZATION_INVALID_MAP_TREE;



	*chunkCount = i;
}

inline void fillBuffer(int* buffer, Json::Value* root, unsigned int* error) {
	//TODO: Fill buffer with data
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
	if (!*target) return false;
	return true;
}

inline bool inView(float angle,float yawn) {
	return angle < GAMEMANAGER_CONVERTER_DEGREE2RADIANS(90) + yawn && angle > yawn;
}

inline void extractEdge(int edge,int* link, int* texture, int* x, int* y, int* portalLink, int* portalChunkIndex) {
	*link = (edge >> 28) & 0xF;             
	*texture = (edge >> 24) & 0xF;          
	*x = (edge >> 17) & 0x7F;               
	*y = (edge >> 10) & 0x7F;               
	*portalLink = (edge >> 6) & 0x1F;       
	*portalChunkIndex = edge & 0x3F;
}