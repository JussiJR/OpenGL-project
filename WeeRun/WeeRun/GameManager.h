#ifndef __gamemanager_h__
#define __gamemanager_h__
#pragma once

#define MaxSizeSSBOs 48

#include <glad/glad.h>

typedef struct GameManager{

	GLuint SSBOs;

}GameManager;


void InitializeGameManager(GameManager* gameManager);

#endif