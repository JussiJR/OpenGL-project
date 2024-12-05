#include "gamemanager.h"

GameManager::GameManager(const char* path)
{
	//!		Ínitialized
	Initialized = 0;

	//!		Initialize Camera
	{
		Entity* plr = (Entity*)malloc(sizeof(plr));
		if (!plr) {
			Initialized = EXCEPTION_GAMEMANAGER_INITIALIZATION_PLAYER_NOSPACE;
			return;
		}
		_camera = Camera(plr, vec2(1.3f, 12.3f));
	}


	//!		Initialize OpenGL objects	
	{
		//!		Get root
		Json::Value root(0);
		getRoot(&root, path, &Initialized);
		if (Initialized) return;
		

		
		//!		Map initialization
		{
			//!		Get buffer length
			edgeCount = getBufferLength(&root, &Initialized);
			if (Initialized) return;

			//!		Create buffer
			int* buffer = (int*)malloc(sizeof(int) * edgeCount); // inconvienent but what can you do?
			fillBuffer(buffer, &root, &Initialized);

			//!		Setup SSBOs
			_mapData = SSBO(edgeCount, buffer, GL_DYNAMIC_STORAGE_BIT, 0);
			free(buffer);
		}
		


	}




	//!		Player state
	_haunted = 0;

	//!		Game settings
	_difficulty = 0;
	_gameMode = 0;

	//!		Counters
	_unixTimer = 0;
	_entityCount = 1;

}

GameManager::~GameManager()
{
	//! Delete rendering stuff
	_vertexArray.Delete();
	_indices.Delete();
	_shader.Delete();
}

int GameManager::Update(int* errorc)
{

	_camera

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

	//FIXME:  MANY MEMORY LOSS SPOT
	vec2 direction,currentPillarPos;
	int* data = new int[edgeCount];
	int texture, x, y, portalLink, portalChunkIndex, value, link;
	
	_shader.Activate(); // not very optimized tho lol :D all tho it is only one and this is securest one XDDD 
	_mapData.Retrieve(0, sizeof(int) * edgeCount, data);
	for (int i = 0;i < edgeCount;i++) {
		//!		Get data
		value = data[i];
		x = (value >> 17) & 0x7F;
		y = (value >> 10) & 0x7F;

		//! Get direction
		direction = vec2(x, y) - _camera.getPointed()->Position;
		float angle, distance;
		distance = getDistance(direction, &angle);

		if(!inView())
	}

	

	delete[] data;
	return *errorc;
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

inline int getBufferLength(Json::Value* root,unsigned int* error) 
{
	
	int edgecount = 0;
	Json::Value::ArrayIndex i = 0;

	Json::Value chunkOffsets;
	if (!isValid(root,&chunkOffsets,"chunkOffsets")) {
		*error = EXCEPTION_GAMEMANAGER_INITIALIZATION_INVALID_MAP_TREE;
		return -1;
	}

	
	
	while (i < chunkOffsets.size() && chunkOffsets[i].asInt() != 0) {
		//							To avoid some random steps I think
		edgecount += chunkOffsets[++i - 1].asInt();
	}

	if (!edgecount) {
		*error = EXCEPTION_GAMEMANAGER_INITIALIZATION_INVALID_MAP_TREE;
		return -1;
	}
	return edgecount;
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

inline float getDistance(vec2 direction,float* angle) {
	float y = sqrt(direction.x * direction.x + direction.y * direction.y);
	*angle = asin(direction.y / y);
	return y/1;
}
inline bool inView(float angle,float yawn) {
	return angle < 2.0943951 && angle > 1.04719755;
}