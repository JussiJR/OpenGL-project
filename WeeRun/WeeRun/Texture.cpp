#include "Texture.h"

TextureBase::TextureBase(const char* path)
{
	glGenTextures(0, &ID);
}
