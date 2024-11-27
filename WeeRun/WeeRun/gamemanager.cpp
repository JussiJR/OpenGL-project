#include "gamemanager.h"

GameManager::GameManager()
{
	//!		Textures
	_mapTextures = TextureBase("");
	_Textures = TextureBase("");
	vector<GLubyte> x;
	//!		Rendering
	_shader = ShaderProgram("","");
	_vertexArray = VAO();
	_indices = EBO(x);

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

	//!		Time scale
	_timeScale = 0;
}

void GameManager::Update(int* errorc)
{
	errorc = 0;
}

void GameManager::Render(int* errorc)
{
	errorc = 0;
}
