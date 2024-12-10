#ifndef VBO_CLASS_H
#define VBO_CLASS_H

#include<glm/glm.hpp>
#include<glad/glad.h>
#include<vector>




class VBO
{
public:
	// Reference ID of the Vertex Buffer Object
	GLuint ID;

	
	VBO();
	// Constructor that generates a Vertex Buffer Object and links it to vertices
	VBO(void* vertices, size_t size);

	// Binds the VBO
	void Bind() const;
	// Unbinds the VBO
	void Unbind() const;
	// Deletes the VBO
	void Delete() const;
};

#endif