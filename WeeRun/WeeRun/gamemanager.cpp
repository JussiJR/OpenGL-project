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
		Json::Value root = getRoot(path, &Initialized);
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
	ifstream in(path, ios::binary);
	if (!in) throw(errno);

	//! Read contents
	string contents;
	in.seekg(0, ios::end);
	contents.resize(in.tellg());
	in.seekg(0, ios::beg);
	in.read(&contents[0], contents.size());
	in.close();
	return contents;

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

inline Json::Value getRoot(const char* path, unsigned int* error) {
	Json::CharReaderBuilder builder;
	Json::Value root;
	std::string errs;

	//? create stream
	std::istringstream s(readFile(path, error));
	if (!Json::parseFromStream(builder, s, &root, &errs)) {
		cout << errs << endl;
		*error = EXCEPTION_GAMEMANAGER_INITIALIZATION_PARSEMAP;
		return NULL;
	}
	return root;
}

inline bool isValid(Json::Value* root,Json::Value* target,const char* name) {
	*target = root->get(name, NULL);
	if (!*target) return false;
	return true;
}