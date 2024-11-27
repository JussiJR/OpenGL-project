#include "SSBO.h"

SSBO::SSBO()
{
	ID = 0;
}

SSBO::SSBO(std::vector<void*> data, GLenum type,int index)
{
	glGenBuffers(1, &ID);
	glNamedBufferStorage(ID, sizeof(uint_fast64_t) *data.size(),(const void*)data.data(),type);
	glBindBufferBase(GL_SHADER_STORAGE_BUFFER,index,ID);
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);

}

void SSBO::Update(GLintptr size,GLintptr offset,const void* data)
{
	glBufferSubData(GL_SHADER_STORAGE_BUFFER,offset,size, data);
}

void SSBO::Activate()
{
}

void SSBO::Delete()
{
}
