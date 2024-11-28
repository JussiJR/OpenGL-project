#include "SSBO.h"

template <typename T> SSBO<T>::SSBO()
{
	ID = 0;
}

template <typename T> SSBO<T>::SSBO(int size,void* data, GLenum type,int index)
{
	glGenBuffers(1, &ID);
	glNamedBufferStorage(ID, sizeof(T) * size,(const void*)data,type);
	glBindBufferBase(GL_SHADER_STORAGE_BUFFER,index,ID);
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
}

template <typename T> void SSBO<T>::Update(GLintptr size,GLintptr offset,const T data)
{
	glBufferSubData(GL_SHADER_STORAGE_BUFFER,offset,size, (void*)data);
}

template <typename T> void SSBO<T>::Activate()
{

}

template <typename T> void SSBO<T>::Delete()
{
}
