#include "SSBO.h"

template <typename T> SSBO<T>::SSBO()
{
	ID = 0;
}

template <typename T> SSBO<T>::SSBO(std::vector<T> data, GLenum type,int index)
{
	glGenBuffers(1, &ID);
	glNamedBufferStorage(ID, sizeof(T) *data.size(),(const void*)data.data(),type);
	glBindBufferBase(GL_SHADER_STORAGE_BUFFER,index,ID);
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);

}

template <typename T> void SSBO<T>::Update(GLintptr size,GLintptr offset,const T data)
{
	glBufferSubData(GL_SHADER_STORAGE_BUFFER,offset,size, data);
}

template <typename T> void SSBO<T>::Activate()
{

}

template <typename T> void SSBO<T>::Delete()
{
}
