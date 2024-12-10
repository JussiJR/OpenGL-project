#pragma once
#ifndef __ubo_h_
#define __ubo_h_

#include <glad/glad.h>
#include "ShaderProgram.h"

class UBO {
private:
	GLint ID;
public:
	GLint BlockIndex;
	void* MemoryMap;
	UBO(size_t size, void* data, GLenum type);
	UBO() :ID(-1),BlockIndex(-1),MemoryMap(nullptr) {}
	void BlockBind(ShaderProgram& program, int bindingBase) const;
	void Update(size_t size, size_t offset, void* data) const;
	void Map(GLenum access, void* data);
	void UnMap() const;
	void Bind() const;

};

#endif