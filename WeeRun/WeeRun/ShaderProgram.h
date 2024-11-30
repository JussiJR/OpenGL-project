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

/// <summary>
/// class Shader program.
/// </summary>
class ShaderProgram {
public:

	/// <summary>
	/// ID to OpenGL shader program
	/// </summary>
	GLuint ID;

	/// <summary>
	/// Empty constructor
	/// </summary>
	ShaderProgram();

	/// <summary>
	/// Constructor for shader program
	/// </summary>
	/// <param name="vertexPath">Path to vertex shader</param>
	/// <param name="fragmentPath">path to frament shader</param>
	ShaderProgram(const char* vertexPath, const char* fragmentPath);

	/// <summary>
	/// Activation method
	/// </summary>
	void Activate();

	/// <summary>
	/// Method for deleting (deletes from gpu's knowledge)
	/// </summary>
	void Delete();

};





#endif // !__shaderprogram_h_
