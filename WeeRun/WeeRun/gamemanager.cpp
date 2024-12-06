#include "gamemanager.h"

GameManager::GameManager(const char* path)
{
	//!		Ínitialized
	Initialized = 0;

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
		

		
		//!		Map initialization
		{
			//!		Get buffer length
			edgeCount = getBufferLength(&root, &Initialized);
			if (Initialized) return;

			//!		Create buffer
			mapBuffer = new int[edgeCount]; 
			fillBuffer(mapBuffer, &root, &Initialized);

			//!		Setup SSBOs
			_mapData = SSBO(edgeCount, mapBuffer, GL_DYNAMIC_STORAGE_BIT, 0);
			
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

	//FIXME:  MANY MEMORY LOSS SPOT
	vec2 direction;
	Pool<int> buffer(10, 0);
	int x, y,edge, last = -1,bufferoffset = chunkOffsets[_camera.getPointed()->CurrentChunk], next = 0;
	bool contin = true;
	_shader.Activate(); // not very optimized tho lol :D all tho it is only one and this is securest one XDDD
	while (contin) {
		//!		Get data
		edge = mapBuffer[next + bufferoffset];
		x = (edge >> 17) & 0x7F;
		y = (edge >> 10) & 0x7F;

		//! Get direction
		direction = vec2(x, y) - _camera.getPointed()->Position;
		float angle, distance;
		distance = getDistance(direction, &angle);
		float yawOffset = _camera.GetRotation().x;
		if (inView(angle, yawOffset)) {
			if (last != -1 && !buffer.Contains(last)) {
				buffer.Push(last);
			}
			buffer.Push(last);
		}

		last = edge;
	}

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
		//					To avoid some random steps I think
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
	*angle = atan2(direction.y, direction.x);
	*angle += *angle < 0 ? 6.28318530718 : 0;
	return sqrt(direction.x * direction.x + direction.y * direction.y);
}
inline bool inView(float angle,float yawn) {
	return angle < 2.0943951 + yawn && angle > yawn;
}