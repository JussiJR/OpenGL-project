// - https://solarianprogrammer.com/2019/06/10/c-programming-reading-writing-images-stb_image-libraries/ - stb image library usage
// - https://www.youtube.com/watch?v=u-00hjlfMKc - Texture loading
// - https://registry.khronos.org/OpenGL-Refpages/gl4/html/glTexParameter.xhtml - texture data info 


#pragma once
#ifndef __texture_h_
#define __texture_h_

#include <glad/glad.h>
#include "stb_image.h"
#include "Exceptions.h"

class Texture {
private:
	GLint ID;
public:
	Texture():ID(-1){}
	Texture(const char* path,unsigned int* errorc, GLint uniformlocation);
	void Bind() const;
	void UnBind() const;
	void Delete() const;
};

#endif