
#include "GameManager.h"
#include <stdio.h>
#include <glad/glad.h>

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif

int InitializeGameManager(GameManager* gameManager, char Vertexpath[], char Fragmentpath[])
{
	char* VertexShaderSource;
	char* FragmentShaderSource;


	//? Create ShaderProgram
	gameManager->ShaderProgram = glCreateProgram();

	free(FragmentShaderSource);
	free(VertexShaderSource);

	return EXIT_SUCCESS;
}
