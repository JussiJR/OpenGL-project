#include "Texture.h"

TextureBase::TextureBase()
{
}

TextureBase::TextureBase(const char* path)
{
	glGenTextures(0, &ID);
}
