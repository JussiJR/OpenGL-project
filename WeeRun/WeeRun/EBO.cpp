#include"EBO.h"

EBO::EBO()
{
	ID = 0;
}

// Constructor that generates a Elements Buffer Object and links it to indices
EBO::EBO(GLubyte* indices, size_t ic)
{
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, ic * sizeof(GLubyte), indices, GL_STATIC_DRAW);
}

// Binds the EBO
void EBO::Bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}

// Unbinds the EBO
void EBO::Unbind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

// Deletes the EBO
void EBO::Delete() const
{
	glDeleteBuffers(1, &ID);
}