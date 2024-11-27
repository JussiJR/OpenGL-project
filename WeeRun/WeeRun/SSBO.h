#pragma once
#ifndef __ssbo_h_
#define __ssbo_h_

#include <GLFW/glfw3.h>
#include <glad/glad.h>


class SSBO {
public:
	GLuint ID;

	SSBO();

	void Update(void* data);
	void Activate();
	void Delete();
};

#endif