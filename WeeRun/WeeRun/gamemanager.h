//- https://developer.valvesoftware.com/wiki/BSP_(Source) - about bsp map files  
// - https://stackoverflow.com/questions/32205981/reading-json-files-in-c - reading 
//	- https://stackoverflow.com/questions/56659583/how-to-read-an-array-of-values-from-json-file-to-c-array - some more info about json file reading
//	
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

//!			Math
//!				Pi
#define MATH_PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647093844609550582231725359408128481117450284102701938521105559644622948954930381964428810975665933446128475648233786783165271201909145648566923460348610454326648213393607260249141273724587006606315588174881520920962829254091715364367892590360011330530548820466521384146951941511609433057270365759591953092186117381932611793105118548074462379962749567351885752724891227938183011949129833673362440656643086021394946395224737190702179860943702770539217176293176752384674818467669405132000568127145263560827785771342757789609173637178721468440901224953430146549585371050792279689258923542019956112129021960864034418159813629774771309960518707211349999998372978049951059731732816096318595024459455346908302642522308253344685035261931188171010003137838752886587533208381420617177669147303598253490428755468731159562863882353787593751957781857780532171226806613001927876611195909216420198938095257201065485863278865936153381827968230301952035301852968995773622599413891249721775283479131515574857242454150695950829533116861727855889075098381754637464939319255060400927701671139009848824012858361603563707660104710181942955596198946767837449448255379774726847104047534646208046684259069491293313677028989152104752162056966024058038150193511253382430035587640247496473263914199272604269922796782354781636009341721641219924586315030286182

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


/// <summary>
/// Game manager handles all updates and almost everything about things
/// </summary>
class GameManager {
private:

	//!		Objects
	
	/// <summary>
	/// Pooled entitys
	/// </summary>
	Pool<Entity> _entitys = Pool<Entity>(10,true);

	/// <summary>
	/// Camera for scene / game
	/// </summary>
	Camera _camera;

	/// <summary>
	/// fifo like container for rendering edges
	/// </summary>
	Pool<float> _screenBuffer = Pool<float>(10, false);



	/// <summary>
	/// Till better solution is found
	/// </summary>
	int* mapBuffer;

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
	
	unsigned int edgeCount;

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
/// gets buffer's desired length
/// </summary>
/// <param name="root">pointer to root value of json</param>
/// <param name="error">pointer to error integer</param>
/// <returns>integer representing buffer's length</returns>
inline int getBufferLength(Json::Value* root, unsigned int* error);


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



#endif
