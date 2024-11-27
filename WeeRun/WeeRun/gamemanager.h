#pragma once
#ifndef __gamemanager_h_
#define __gamemanager_h_

#include "Texture.h"
#include "VBO.h"
#include "EBO.h"
#include "VAO.h"
#include "ShaderProgram.h"
#include <iostream>
#include "SSBO.h"

#define EXCEPTION_GAMEMANAGER_INITIALIZATION_MAPNOTFOUND 0x301F
#define EXCEPTION_GAMEMANAGER_INITÍALIZATION_SHADER_VERTEXNOTFOUND 0x302F
#define EXCEPTION_GAMEMANAGER_INITIALIZATION_SHADER_FRAGMENTNOTFOUND 0x303F
#define EXCEPTION_GAMEMANAGER_INITIALIZATION_SHADER_TEXTURENOTFOUND 0x304F

#define ENTITY_PLAYER_INDEX 0

#define TIMESCALE_SCALE -0.5f
#define GAMEMANAGER_GRAVITY -9.81


class GameManager {
private:

	//!		Textures
	TextureBase _mapTextures;
	TextureBase _Textures;

	//!		Objects
	SSBO _mapData;
	SSBO _entityData;

	//!		Rendering
	ShaderProgram _shader;
	VAO _vertexArray;
	EBO _indices;

	//!		Uniforms
	GLuint _viewMatrixUniform;
	GLuint _basePositionUniform;

	//!		Player	
	unsigned int _haunted : 1;
	
	//!		Game settings
	unsigned int _difficulty : 3;
	unsigned int _gameMode : 1;

	//!		Counters
	unsigned int _unixTimer : 12;
	unsigned int _entityCount : 7;

	//!		Render settings
	unsigned int _fieldOfView: 7;


public:
	//!		Time scale
	unsigned int Initialized;

	GameManager(const char* path);
	~GameManager();

	void Update(int* errorc);

	void Render(int* errorc,float render_distance);
};

#endif
