#pragma once
#ifndef __ssbo_h_
#define __ssbo_h_

//!		GLFW
#if !defined(__glfw3_h_)

//!			Definitions
#if !defined(GLFW_INCLUDE_NONE)
#define GLFW_INCLUDE_NONE
#endif
//!			Header files
#include <GLFW/glfw3.h>

#endif

//!		OpenGL
#include <glad/glad.h>

//!		stdint
#include <stdint.h>

//!		Vector
#include <vector>
class SSBO {
public:
	GLuint ID;

	SSBO();
	SSBO(std::vector<void*> data, GLenum type);

	void Update(void* data);
	void Activate();
	void Delete();
};

#endif