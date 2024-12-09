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
	Position = position;
}

Entity::Entity(unsigned char textureIndex, float x, float y)
{
	CurrentChunk = 0;
	TextureIndex = textureIndex;
	Position = glm::vec2(x,y);
}

Entity& Entity::operator>>(glm::vec3& force)
{
	Velocity += glm::vec2(force.x,force.y);
	// TODO: insert return statement here
	return *this;
}

Entity& Entity::operator>>(glm::vec2& force)
{
	Position += force;
	// TODO: insert return statement here
	return *this;
}
