#include "Texture.h"

Texture::Texture(const char* path)
{
	int width, height, channels;
	unsigned char* img = stbi_load(path, &width, &height, &channels, 0);
	if (!img) throw(Texture_Exception);
	glGenTextures(1, (GLuint*) & ID);
	glActiveTexture(GL_TEXTURE0);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, img);
}

void Texture::Bind() const
{
	glBindTexture(GL_TEXTURE_2D, ID);
}

void Texture::UnBind() const
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::Delete() const
{
	glDeleteTextures(1, (GLuint*)&ID);
}
