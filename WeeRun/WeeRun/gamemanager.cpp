#include "gamemanager.h"


/// <summary>
/// Reads data from file and returns it in string
/// </summary>
/// <param name="path">path to file</param>
/// <param name="error">pointer to error integer</param>
/// <returns>string here data is</returns>
inline string readFile(const char* path,unsigned int* error);

/// <summary>
/// gets buffer's desired length
/// </summary>
/// <param name="root">pointer to root value of json</param>
/// <param name="error">pointer to error integer</param>
/// <returns>integer representing buffer's length</returns>
inline int getBufferLength(Json::Value* root,unsigned int* error);

/// <summary>
/// gets root of file
/// </summary>
/// <param name="path">path to root file</param>
/// <param name="error">error integer</param>
/// <returns>returns Json::Value representing root</returns>
inline Json::Value getRoot(const char* path,unsigned int* error);

/// <summary>
/// Fills buffer with map data
/// </summary>
/// <param name="buffer">pointer to target buffer</param>
/// <param name="root">pointer to root </param>
/// <param name="error">pointer to error integer</param>
inline void fillBuffer(int* buffer, Json::Value* root, unsigned int* error);


void GameManager::changeMapValue(size_t offset, size_t size, void* data) const
{
	glBufferSubData(GL_SHADER_STORAGE_BUFFER, offset, size, (void*)data);
}

GameManager::GameManager(const char* path)
{
	//!		Ínitialized
	
	Initialized = 0;
	
	//!		Load map	
	{
		//!		Get root
		Json::Value root = getRoot(path, &Initialized);
		if (Initialized) return;

		//!		Get buffer length
		int edgecount = getBufferLength(&root,&Initialized);
		if (Initialized) return;

		//!		Create buffer
		int* buffer = (int*)malloc(sizeof(int) * edgecount); // inconvienent but what can you do?
		fillBuffer(buffer, &root, &Initialized);

		//!		Setup SSBOs
		glGenBuffers(1, &_mapData);
		glNamedBufferStorage(_mapData, sizeof(int) * edgecount, (const void*)buffer
			,GL_DYNAMIC_STORAGE_BIT);
		glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, _mapData);
		glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
		free(buffer);
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

	int edgecount;
	Json::Value::ArrayIndex i = 0;

	const Json::Value chunkOffsets = &root->get("chunkOffsets", NULL);
	if (!chunkOffsets) {
		*error = EXCEPTION_GAMEMANAGER_INITIALIZATION_INVALID_MAP_TREE;
		return;
	}

	
	
	while (i < chunkOffsets.size() && chunkOffsets[i].asInt() != 0) {
		//							To avoid some random steps I think
		edgecount += chunkOffsets[++i - 1].asInt();
	}

	if (!edgecount) {
		*error = EXCEPTION_GAMEMANAGER_INITIALIZATION_INVALID_MAP_TREE;
		return;
	}
}

inline void fillBuffer(int* buffer, Json::Value* root, unsigned int* error) {

}

inline Json::Value getRoot(const char* path, unsigned int* error) {
	Json::CharReaderBuilder builder;
	Json::Value root;
	std::string errs;
	std::istringstream s(readFile(path, error));
	if (!Json::parseFromStream(builder, s, &root, &errs)) {
		cout << errs << endl;
		*error = EXCEPTION_GAMEMANAGER_INITIALIZATION_PARSEMAP;
		return NULL;
	}
	return root;
}