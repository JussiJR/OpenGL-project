#pragma once
#ifndef __shaderprogram_h_
#define __shaderprogram_h_

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>

using namespace std;

class ShaderProgram {
public:
	GLuint ID;

	ShaderProgram();
	ShaderProgram(const char* vertexPath, const char* fragmentPath);

	void Activate();
	void Delete();

};





#endif // !__shaderprogram_h_
