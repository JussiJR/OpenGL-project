#include "SSBO.h"

SSBO::SSBO()
{
	ID = 0;
}

SSBO::SSBO(std::vector<void*> data, GLenum type)
{
	glGenBuffers(1, &ID);
	glNamedBufferStorage(ID,
		sizeof(uint_fast64_t) *data.size(),
		(const void*)data.data(),
		GL_DYNAMIC_STORAGE_BIT);
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
