#ifndef __gamemanager_h__
#define __gamemanager_h__
#pragma once
#pragma pack(1)


#define GAMEMANAGER_DIFFICULTY_NULL 0
#define GAMEMANAGER_DIFFICULTY_EASY 1
#define GAMEMANAGER_DIFFICULTY_NORMAL 2
#define GAMEMANAGER_DIFFICULTY_HARD 3
#define GAMEMANAGER_DIFFICULTY_INSANE 4
#define GAMEMANAGER_DIFFICULTY_DEATHMODE 5
#define GAMEMANAGER_DIFFICULTY_DEATHNOTE 6



#define GAMEMANAGER_GAMEMODE_TAG 1
#define GAMEMANAGER_GAMEMODE_NIGHTMARE 2

#define ENTITY_PLAYER_INDEX 0


#include <glad/glad.h>



typedef struct GameManager{

	//!	New Counter's
	unsigned short int EntityCount : 8;		// Entity counter
	unsigned char Difficulty : 3;			// Difficulty
	unsigned char GameMode : 2;				// GameMode
	unsigned char Haunted : 3;				// Is player's position known
	unsigned int Points : 32;				// Point Counter
	
	//!	Settings
	 

	//!	OpenGL stuff
	GLuint VertexPoints;	// SSBOs
	GLuint Entitys;			// SSBOs
	GLuint VBO;				// VBO
	GLuint EBO;				// EBO
	GLuint VAO;				// VAO
	GLuint ViewMatrix;		// Uniform

	

}GameManager;


void InitializeGameManager(GameManager* gameManager);
#pragma pack(pop)
#endif