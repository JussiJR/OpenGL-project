#include "SSBO.h"

SSBO::SSBO()
{
	ID = 0;
}
SSBO::SSBO(int size,void* data, GLenum type,int index)
{
	glGenBuffers(1, &ID);
	glNamedBufferStorage(ID, sizeof(int) * size,(const void*)data,type);
	glBindBufferBase(GL_SHADER_STORAGE_BUFFER,index,ID);
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
}

void SSBO::Update(GLintptr size,GLintptr offset,const int data)
{
	glBufferSubData(GL_SHADER_STORAGE_BUFFER,offset,size, (void*)data);
}

void SSBO::Activate()
{

}

void SSBO::Delete()
{
}
