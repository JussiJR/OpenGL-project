//- https://developer.valvesoftware.com/wiki/BSP_(Source) - about bsp map files  
// - https://stackoverflow.com/questions/32205981/reading-json-files-in-c - reading 
//	- https://stackoverflow.com/questions/56659583/how-to-read-an-array-of-values-from-json-file-to-c-array - some more info about json file reading

#pragma once
#ifndef __gamemanager_h_
#define __gamemanager_h_

//!	Includes
//!		VBO
#include "VBO.h"

//!		EBO
#include "EBO.h"

//!		VAO
#include "VAO.h"

//!		Shader program
#include "ShaderProgram.h"

//!		Iostream
#include <iostream>

//!		Shader storage buffer object
#include "SSBO.h"

//!		GLM
//!			Header files
#include <glm/glm.hpp>
#include <glm/packing.hpp>
#include <glm/mat4x4.hpp>
#include <glm/mat4x3.hpp>
#include <glm/mat4x2.hpp>
#include <glm/mat3x4.hpp>
#include <glm/mat2x4.hpp>
#include <glm/ext/matrix_float4x4.hpp>

//!		json
//!			Header files		
#include <json/value.h>
#include <json/json.h>

//!		fstream
//!			header files
#include <fstream>

//!	Definitions
//!		Exceptions
//!			Game manager
//!				Initialization
#define EXCEPTION_GAMEMANAGER_INITIALIZATION_MAPNOTFOUND 0x301F
#define EXCEPTION_GAMEMANAGER_INITIALIZATION_PARSEMAP 0x305F
#define EXCEPTION_GAMEMANAGER_INITIALIZATION_INVALID_MAP_TREE 0x306F
#define EXCEPTION_GAMEMANAGER_INITÍALIZATION_SHADER_VERTEXNOTFOUND 0x302F
#define EXCEPTION_GAMEMANAGER_INITIALIZATION_SHADER_FRAGMENTNOTFOUND 0x303F
#define EXCEPTION_GAMEMANAGER_INITIALIZATION_SHADER_TEXTURENOTFOUND 0x304F

//!		Constant values
//!			Entity
//!				Player
#define ENTITY_PLAYER_INDEX 0

//!			Time scale
#define TIMESCALE_SCALE -0.5f

//!			Game manager
#define GAMEMANAGER_GRAVITY -9.81

//!				Renderer
#define GAMEMANAGER_RENDERER_DISTANCE 5

//!				Converter
#define GAMEMANAGER_CONVERTER_DEGREE2RADIANS(fov) ((float)fov * 0.0174532925f);


class GameManager {
private:

	//!		Objects
	
	/// <summary>
	/// SSBO for _Map's data ( Will not change after loading map
	/// </summary>
	GLuint _mapData;


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
	unsigned int _unixTimer : 13;

	/// <summary>
	/// how many entities are in map ( includes entity that represents player ) 
	/// </summary>
	unsigned int _entityCount : 7;

	//!		Render settings
	
	/// <summary>
	/// Field of View for calculations and for those who wish to use cheat engine to break rendering system.
	/// </summary>
	unsigned int _fieldOfView: 7;

	/// <summary>
	/// Current chunk where player is
	/// </summary>
	unsigned char _currentChunk;

	/// <summary>
	/// Player's yaw
	/// </summary>
	float _yaw;

	void changeMapValue(size_t offset, size_t size, void* data);

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
	/// Method for fixed updating game ( Called fixed amount in second )
	/// </summary>
	/// <param name="errorc"> call back return for backtracking etc.</param>
	/// <returns>0 if all goes according to plan otherwise error code as hexadecimal.</returns>
	int FixedUpdate(int* errorc);

	/// <summary>
	/// Method for rendering ( called once every frame )
	/// </summary>
	/// <param name="errorc"> callback kind of value</param>
	/// <param name="render_distance">constant num of render distance ( aka how much game will render</param>
	int Render(int* errorc,int render_distance);
};

#endif
