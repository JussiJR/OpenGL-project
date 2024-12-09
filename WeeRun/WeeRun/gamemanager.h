//- https://developer.valvesoftware.com/wiki/BSP_(Source) - about bsp map files  
//	- https://stackoverflow.com/questions/32205981/reading-json-files-in-c - reading 
//	- https://stackoverflow.com/questions/56659583/how-to-read-an-array-of-values-from-json-file-to-c-array - some more info about json file reading
//	- https://stackoverflow.com/questions/35271222/getting-the-angle-from-a-direction-vector - vec to radians direction
//	- 

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
//!			Header files
#include <fstream>

//!		Pool
//!			Header files
#include "Pool.h"

//!		Camera
//!			Header files
#include "Camera.h"

//!		Math
//!			Header files
#include <cmath>

//!		Main
//!			Header files
#include "main.h"

//!		Queue
//!			Header files
#include <queue>

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
#define EXCEPTION_GAMEMANAGER_INITIALIZATION_PLAYER_NOSPACE 0x501F

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
//!					Degree 2 radians
#define GAMEMANAGER_CONVERTER_DEGREE2RADIANS(fov) ((float)fov * 0.0174532925f);

//!	Namespace usages
using namespace std;

/// <summary>
/// Game manager handles all updates and almost everything about things
/// </summary>
class GameManager {
private:

	//!		Objects
	
	/// <summary>
	/// Pooled entitys
	/// </summary>
	Pool<Entity> _entitys = Pool<Entity>(10,1);

	int _chunkOffsets[63];
	int _chunkSizes[63];
	/// <summary>
	/// Camera for scene / game
	/// </summary>
	Camera _camera;

	/// <summary>
	/// Till better solution is found
	/// </summary>
	int* _mapBuffer;

	/// <summary>
	/// SSBO for _Map's data ( Will not change after loading map
	/// </summary>
	SSBO _mapData;


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


/// <summary>
/// Reads data from file and returns it in string
/// </summary>
/// <param name="path">path to file</param>
/// <param name="error">pointer to error integer</param>
/// <returns>string here data is</returns>
inline string readFile(const char* path, unsigned int* error);

/// <summary>
/// 
/// </summary>
/// <param name="root"></param>
/// <param name="error"></param>
/// <param name="edgecount"></param>
/// <param name="chunkCount"></param>
/// <param name="_chunkSizes"></param>
/// <param name="_chunkOffsets"></param>
inline void getBufferLength(Json::Value* root, unsigned int* error, int* edgecount, int* chunkCount, int _chunkSizes[63], int _chunkOffsets[63]);


/// <summary>
/// gets root of file
/// </summary>
/// <param name="path">path to root file</param>
/// <param name="error">error integer</param>
/// <returns>returns Json::Value representing root</returns>
void getRoot(Json::Value *root,const char* path, unsigned int* error);

/// <summary>
/// Fills buffer with map data
/// </summary>
/// <param name="buffer">pointer to target buffer</param>
/// <param name="root">pointer to root </param>
/// <param name="error">pointer to error integer</param>
inline void fillBuffer(int* buffer, Json::Value* root, unsigned int* error);

/// <summary>
/// Checks if target name is in root
/// </summary>
/// <param name="root">value to check from</param>
/// <param name="target">objet to be assigned</param>
/// <param name="name">name of the object</param>
/// <returns>true if it is found otherwise false</returns>
inline bool isValid(Json::Value* root, Json::Value* target, const char* name);

/// <summary>
/// Calculates distance (c) and sets angle in radians 
/// </summary>
/// <param name="direction"></param>
/// <param name="angle"></param>
/// <returns>distance between Vector point and player</returns>
inline float getDistance(vec2 direction, float* angle);

/// <summary>
/// Checks if object is in view.
/// </summary>
/// <param name="angle">angle where object is from player in fixed map</param>
/// <param name="yawn">rotation of player or rather offset for angle</param>
/// <returns>true if object is in view otherwise false. </returns>
inline bool inView(float angle, float yawn);

/// <summary>
/// 
/// </summary>
/// <param name="edge"></param>
/// <param name="link"></param>
/// <param name="texture"></param>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="portalLink"></param>
/// <param name="portalChunkIndex"></param>
inline void extractEdge(int edge, int* link, int* texture, int* x, int* y, int* portalLink, int* portalChunkIndex);
#endif
