
//https://ktstephano.github.io/rendering/opengl/ssbos - SSBOs usage
//https://learnopengl.com/Getting-started/Shaders - Shader creation
//https://community.khronos.org/t/multiple-ssbos-access/111107 - SSBOs info more

#ifndef __gamemanager_h__
#define __gamemanager_h__
#pragma once
#pragma pack(1)


#define GAMEMANAGER_INITIALIZATION_VERTEXSHADER_FAILURE -0xCAAF
#define GAMEMANAGER_INITIALIZATION_FRAGMENTSHADER_FAILURE -0xCABF
#define GAMEMANAGER_INITIALIZATION_SHADERPROGRAM_FAILURE -0xCACF

#define GAMEMANAGER_DIFFICULTY_NULL 0
#define GAMEMANAGER_DIFFICULTY_EASY 1
#define GAMEMANAGER_DIFFICULTY_NORMAL 2
#define GAMEMANAGER_DIFFICULTY_HARD 3
#define GAMEMANAGER_DIFFICULTY_INSANE 4
#define GAMEMANAGER_DIFFICULTY_DEATHMODE 5
#define GAMEMANAGER_DIFFICULTY_DEATHNOTE 6

#define CHUNK_SIZE_PHYSICAL (63 * 8)
#define MAP_SIZE_PHYSICAL CHUNK_SIZE_PHYSICAL * 255

#define ENTITY_SIZE_PYHSICAL 630

#define GAMEMANAGER_GAMEMODE_TAG 1
#define GAMEMANAGER_GAMEMODE_NIGHTMARE 2

#define HAUNTED_STATE_UNSEEN 0
#define HAUNTED_STATE_HAUNTED 1
#define HAUNTED_STATE_AGROED 2s

#define ENTITY_PLAYER_INDEX 0


#include <glad/glad.h>
#include "VectorPoint.h"

/*
* Used to represent contain all data in one place
*/
typedef struct GameManager{

	//!	New Counter's
	unsigned long long EntityCount : 6;		// Entity counter
	unsigned long long Counter : 51;		// Second Counter
	
	//!	Settings
	unsigned long long Difficulty : 3;		// Difficulty
	unsigned long long GameMode : 2;		// GameMode

	//!	Player data
	unsigned long long Haunted : 2;			// Is player's position known
	float pitch;							// Pitch of the player
	float yawn;								// Yawn of the player

	//!	OpenGL stuff
	GLuint VertexPoints;	// SSBOs
	GLuint Entitys;			// SSBOs
	GLuint ViewMatrix;		// Uniform
	GLuint ShaderProgram;	//Shader program


}GameManager;

/*
* NAME: InitializeGameManager
* SUMMARY:
*	Constructor for GameManager struct
* PARAMS:
*	- GameManager* gameManager : target GameManager to be initialized
*	- char* Vertexpath : Path to Vertexshader file
*	- char* Fragmentpath : Path to Fragment file
* KNOWN ISSUES: 
*	- NoN
* RETURNS: 
*	0 if success otherwise error code as integer
*/
int InitializeGameManager(GameManager* gameManager,char* Vertexpath,char* Fragmentpath);


/*
* NAME: InitializeGameManager
* SUMMARY:
*	Clean up method for GameManager struct
* PARAMS:
*	- GameManager* gameManager : target GameManager to be cleaned
* KNOWN ISSUES:
*	- NoN
*/
void CleanupGameManager(GameManager* gameManager);
#pragma pack(pop)
#endif