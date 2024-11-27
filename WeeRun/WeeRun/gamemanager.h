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
	
	/// <summary>
	/// SSBO for _Map's data ( Will not change after loading map
	/// </summary>
	SSBO _mapData;

	/// <summary>
	/// SSBO for Entitys
	/// </summary>
	SSBO _entityData;

	//!		Rendering
	
	/// <summary>
	/// Shader program 
	/// </summary>
	ShaderProgram _shader;

	/// <summary>
	/// vertexArray of sizes for instanced rendering
	/// </summary>
	VAO _vertexArray;

	/// <summary>
	/// Indices 
	/// </summary>
	EBO _indices;

	//!		Uniforms
	
	/// <summary>
	/// ViewMatrix uniform link 
	/// </summary>
	GLuint _viewMatrixUniform;

	//!		Player	
	
	/// <summary>
	/// Is player haunted (does enemies get your location
	/// </summary>
	unsigned int _haunted : 1;
	
	//!		Game settings
	
	/// <summary>
	/// Difficulty level or damage multiplier and health multiplier
	/// </summary>
	unsigned int _difficulty : 3;
	
	/// <summary>
	/// Game objective
	/// </summary>
	unsigned int _gameMode : 1;

	//!		Counters
	
	/// <summary>
	/// Timer with atleast of 1 hour or 68 minutes to be exact and 1/4 of minute on top 
	/// </summary>
	unsigned int _unixTimer : 12;

	/// <summary>
	/// how many entities are in map ( includes entity that represents player ) 
	/// </summary>
	unsigned int _entityCount : 7;

	//!		Render settings
	
	/// <summary>
	/// Field of View for calculations and for those who wish to use cheat engine to break rendering system.
	/// </summary>
	unsigned int _fieldOfView: 7;


public:

	/// <summary>
	/// Gives data about is game manager properly initialized.
	/// </summary>
	unsigned int Initialized;

	/// <summary>
	/// One and only constructor
	/// </summary>
	/// <param name="path">Path to map</param>
	GameManager(const char* path);

	/// <summary>
	/// Destructor
	/// </summary>
	~GameManager();

	/// <summary>
	/// Method for updating game ( called once every frame )
	/// </summary>
	/// <param name="errorc">kind of call back to return error it may have countered</param>
	int Update(int* errorc);

	/// <summary>
	/// Method for rendering ( called once every frame )
	/// </summary>
	/// <param name="errorc"> callback kind of value</param>
	/// <param name="render_distance">constant float of render distance ( aka how much game will render</param>
	int Render(int* errorc,float render_distance);


};

#endif
