#include "SSBO.h"

SSBO::SSBO()
{
	/*
	glGenBuffers(1, &ID);
	glBindBuffer(GL_SHADER_STORAGE, ID);
	glBufferData(GL_SHADER_STORAGE_BUFFER, sizeof(data), data​, GLenum usage); //sizeof(data) only works for statically sized C/C++ arrays.
	glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 3, ssbo);
	*/
	}

void SSBO::Update(void* data)
{
}
