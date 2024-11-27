#include "gamemanager.h"

GameManager::GameManager(const char* path)
{
	//!		Initialized
	Initialized = 0;

	//!		Textures
	_mapTextures;
	_Textures;
	//!		Rendering
	_shader;
	_vertexArray;
	_indices;

	//!		Uniforms
	_viewMatrixUniform = 0;
	_basePositionUniform = 0;

	//!		Player	
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

	//! Delete object stuff
	_mapData.Delete();
	_entityData.Delete();

	//!		Player	
	_haunted = 0;

	//!		Game settings
	_difficulty = 0;
	_gameMode = 0;

	//!		Counters
	_unixTimer = 0;
	_entityCount = 1;

	//!		Render settings
	_fieldOfView = 90;

	//!		Time scale
	Initialized = 0;
}

void GameManager::Update(int* errorc)
{
	errorc = 0;
}

void GameManager::Render(int* errorc,float render_distance)
{
	errorc = 0;
}
