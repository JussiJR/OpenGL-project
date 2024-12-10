#include "UBO.h"

UBO::UBO(size_t size, void* data, GLenum type) : MemoryMap(nullptr),BlockIndex(-1)
{
	glGenBuffers(1, (GLuint*) & ID);
	Bind();
	glBufferData(GL_UNIFORM_BUFFER, size, data, type);
}

void UBO::BlockBind(ShaderProgram& program,int bindingBase) const
{
	if(BlockIndex == -1) glGetUniformBlockIndex(program.ID, "MyUniformBlock");
	glUniformBlockBinding(program.ID, BlockIndex, bindingBase); 
	glBindBufferBase(GL_UNIFORM_BUFFER, 0, ID);
}

void UBO::Update(size_t size, size_t offset, void* data) const
{
	Bind();
	glBufferSubData(GL_UNIFORM_BUFFER, offset, size, &data);
}

void UBO::UnMap() const
{
	glUnmapBuffer(GL_UNIFORM_BUFFER);
}

void UBO::Bind() const
{
	glBindBuffer(GL_UNIFORM_BUFFER, ID);
}

void UBO::Map(GLenum access,void* data)
{
	Bind(); // just to be sure
	MemoryMap = glMapBuffer(GL_UNIFORM_BUFFER, access);
	if (MemoryMap) {
		memcpy(MemoryMap, data, sizeof(data));
	}
}
