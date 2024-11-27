#pragma once
#ifndef __gamemanager_h_
#define __gamemanager_h_
#pragma pack(1)

#include "Texture.h"
#include "VBO.h"
#include "EBO.h"
#include "VAO.h"
#include "ShaderProgram.h"
#include <iostream>
#include "SSBO.h"


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

	//!		Time scale
	unsigned int _timeScale : 1;
public:

	GameManager(const char* path);
	~GameManager();

	void Update(int* errorc);

	void Render(int* errorc,float render_distance);
};

#pragma pack(pop)
#endif
