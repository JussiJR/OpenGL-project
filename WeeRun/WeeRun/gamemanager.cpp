#include "gamemanager.h"





void GameManager::changeMapValue(size_t offset, size_t size, void* data) const
{
	glBufferSubData(GL_SHADER_STORAGE_BUFFER, offset, size, (void*)data);
}

GameManager::GameManager(const char* path)
{
	//!		Ínitialized
	Initialized = 0;
	
	//!		Initialize OpenGL objects	
	{
		//!		Get root
		Json::Value root(0);
		getRoot(&root, path, &Initialized);
		if (Initialized) return;
		

		
		//!		Map initialization
		{
			//!		Get buffer length
			int edgecount = getBufferLength(&root, &Initialized);
			if (Initialized) return;

			//!		Create buffer
			int* buffer = (int*)malloc(sizeof(int) * edgecount); // inconvienent but what can you do?
			fillBuffer(buffer, &root, &Initialized);

			//!		Setup SSBOs
			_mapData = SSBO(edgecount, buffer, GL_DYNAMIC_STORAGE_BIT, 0);
			free(buffer);
		}

		//!		Texture loading
		{
			//!	Get texture path
			Json::Value chunkOffsets;
			if (!isValid(&root, &chunkOffsets, "Textures")) {
				Initialized = EXCEPTION_GAMEMANAGER_INITIALIZATION_INVALID_MAP_TREE;
				return;
			}



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

	//!		Render settings
	_fieldOfView = 90;
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
	_shader.Activate(); // not very optimized tho lol :D all tho it is only one and this is securest one XDDD 



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