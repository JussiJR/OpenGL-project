//- https://developer.valvesoftware.com/wiki/BSP_(Source) - about bsp map files  
//	- https://stackoverflow.com/questions/32205981/reading-json-files-in-c - reading 
//	- https://stackoverflow.com/questions/56659583/how-to-read-an-array-of-values-from-json-file-to-c-array - some more info about json file reading
//	- https://stackoverflow.com/questions/35271222/getting-the-angle-from-a-direction-vector - vec to radians direction
//	- https://www.youtube.com/watch?v=EqNcqBdrNyI - Projection matrices
//	- https://registry.khronos.org/OpenGL-Refpages/gl4/html/glGetUniformLocation.xhtml - Get uniform location
//	- https://stackoverflow.com/questions/21967506/cant-set-uniform-value-in-opengl-shader - Set value to uniform
//	- https://www.youtube.com/watch?v=R-bjXOEQyX8 - Some Vertex shader ideas
//	- https://www.youtube.com/watch?v=hf27qsQPRLQ - some optimizations
//	- https://www.youtube.com/watch?v=L_YTFlnCLVE - Some Valve Portal linking ideas
#pragma once
#ifndef __gamemanager_h_
#define __gamemanager_h_

//!	Includes
//!		VBO
#include "VBO.h"
#include "VAO.h"
#include "ShaderProgram.h"
#include <iostream>
#include "SSBO.h"
#include <glm/glm.hpp>
#include <glm/packing.hpp>
#include <glm/matrix.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <json/value.h>
#include <json/json.h>
#include <fstream>
#include "Pool.h"
#include "Camera.h"
#include <cmath>
#include "main.h"
#include <queue>
#include "Edge.h"
#include "UBO.h"
#define GAMEMANAGER_CONVERTER_DEGREE2RADIANS(fov) ((float)fov * 0.0174532925f);

//!	Constexpr
constexpr float fov = 1.570796f;

//!	Classes

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

	/// <summary>
	/// Camera for scene / game
	/// </summary>
	Camera  _camera;

	int* _chunkOffsets;
	int* _chunkSizes;
	
	/// <summary>
	/// Till better solution is found
	/// </summary>
	edge _mapBuffer[512];

	/// <summary>
	/// UBO for _Map's data ( Will not change after loading map
	/// </summary>
	UBO _edgeData;


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
	/// Vertex buffer object for vertex array
	/// </summary>
	VBO _vertexbuffer;

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
/// 
/// </summary>
/// <param name="buffer"></param>
/// <param name="root"></param>
/// <param name="error"></param>
inline void fillBuffer(edge* buffer, Json::Value* root, unsigned int* error);

/// <summary>
/// 
/// </summary>
/// <param name="root"></param>
/// <param name="error"></param>
/// <param name="edgecount"></param>
/// <param name="chunkCount"></param>
/// <param name="_chunkSizes"></param>
/// <param name="_chunkOffsets"></param>
inline void getBufferLength(Json::Value* root, unsigned int* error, int* edgecount, int* chunkCount, int* _chunkSizes, int* _chunkOffsets);


/// <summary>
/// gets root of file
/// </summary>
/// <param name="path">path to root file</param>
/// <param name="error">error integer</param>
/// <returns>returns Json::Value representing root</returns>
void getRoot(Json::Value *root,const char* path, unsigned int* error);

/// <summary>
/// Checks if target name is in root
/// </summary>
/// <param name="root">value to check from</param>
/// <param name="target">objet to be assigned</param>
/// <param name="name">name of the object</param>
/// <returns>true if it is found otherwise false</returns>
inline bool isValid(Json::Value* root, Json::Value* target, const char* name);
#endif
