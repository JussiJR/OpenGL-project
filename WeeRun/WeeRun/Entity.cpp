#include "Entity.h"
Entity::Entity(unsigned char textureIndex)
{
	CurrentChunk = 0;
	TextureIndex = textureIndex;
	Position = glm::vec2(0);
}

Entity::Entity(unsigned char textureIndex, glm::vec2 position)
{
	CurrentChunk = 0;
	TextureIndex = textureIndex;
	this->Position = position;
}

Entity::Entity(unsigned char textureIndex, float _x, float _y)
{
	CurrentChunk = 0;
	TextureIndex = textureIndex;
	Position = glm::vec2(_x, _y);
}

