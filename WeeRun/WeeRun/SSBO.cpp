#include "SSBO.h"

SSBO::SSBO()
{
	glGenBuffers(1, &ID);
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, ID);
	glBufferData(GL_SHADER_STORAGE_BUFFER, sizeof(int) * , data​, GLenum usage); //sizeof(data) only works for statically sized C/C++ arrays.
	glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 3, ID);
}

void SSBO::Update(void* data)
{
}

void SSBO::Activate()
{
}

void SSBO::Delete()
{
}
