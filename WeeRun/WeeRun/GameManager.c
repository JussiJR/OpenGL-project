
#include "GameManager.h"
#include <stdio.h>
#include <glad/glad.h>



#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif

int InitializeGameManager(GameManager* gameManager, char* Vertexpath, char* Fragmentpath)
{
	int status;
	char* VertexShaderSource;
	char* FragmentShaderSource;


	//! Source VertexShaderCode
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, VertexShaderSource, NULL);
	glCompileShader(vertexShader);
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);
	if (!status) {
		free(FragmentShaderSource);
		free(VertexShaderSource);
		free(Vertexpath);
		free(Fragmentpath);
		return GAMEMANAGER_INITIALIZATION_VERTEXSHADER_FAILURE;
	}

	//! Shader FragmentShaderCode
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, FragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &status);
	if (!status) {
		free(FragmentShaderSource);
		free(VertexShaderSource);
		free(Vertexpath);
		free(Fragmentpath);
		return GAMEMANAGER_INITIALIZATION_FRAGMENTSHADER_FAILURE;
	}

	//? Create ShaderProgram
	gameManager->ShaderProgram = glCreateProgram();
	glAttachShader(gameManager->ShaderProgram, vertexShader);
	glAttachShader(gameManager->ShaderProgram, fragmentShader);
	glGetShaderiv(gameManager->ShaderProgram, GL_LINK_STATUS, &status);
	if (!status) {
		free(FragmentShaderSource);
		free(VertexShaderSource);
		free(Vertexpath);
		free(Fragmentpath);
		return GAMEMANAGER_INITIALIZATION_VERTEXSHADER_FAILURE;
	}
	


	glUseProgram(gameManager->ShaderProgram);

	free(FragmentShaderSource);
	free(VertexShaderSource);
	free(Vertexpath);
	free(Fragmentpath);
	
	return EXIT_SUCCESS;
}

void CleanupGameManager(GameManager* gameManager)
{
	
}
