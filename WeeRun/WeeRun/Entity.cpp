#include "Entity.h"
Entity::Entity(unsigned char textureIndex)
{
	CurrentChunk = 0;
	TextureIndex = textureIndex;
	x = y = 0;
}

Entity::Entity(unsigned char textureIndex, glm::vec2 position)
{
	CurrentChunk = 0;
	TextureIndex = textureIndex;
	x = position.x;
	y = position.y;
}

Entity::Entity(unsigned char textureIndex, float _x, float _y)
{
	CurrentChunk = 0;
	TextureIndex = textureIndex;
	x = _x;
	y = _y;
}

Entity& Entity::operator>>(glm::vec3& force)
{
	Velocity += glm::vec2(force.x,force.y);
	// TODO: insert return statement here
	return *this;
}

Entity& Entity::operator>>(glm::vec2& force)
{
	x += force.x;
	y += force.y;
	// TODO: insert return statement here
	return *this;
}
