#pragma once
#ifndef __texture_h_
#define __texture_h_

#include <glad/glad.h>

class TextureBase {
public:

	GLuint ID;
	TextureBase();
	TextureBase(const char* path);



};

#endif