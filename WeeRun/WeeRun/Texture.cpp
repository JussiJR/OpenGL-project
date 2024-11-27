#include "Texture.h"

TextureBase::TextureBase()
{
	ID = 0;
}

TextureBase::TextureBase(const char* path)
{
	glGenTextures(0, &ID);
}
