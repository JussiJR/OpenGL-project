#include "Entity.h"
Entity::Entity(unsigned char textureIndex)
{
	CurrentChunk = 0;
	TextureIndex = textureIndex;
	Position = vec2(0);
	Velocity = vec3(0);
}

Entity::Entity(unsigned char textureIndex, vec2 position)
{
	CurrentChunk = 0;
	TextureIndex = textureIndex;
	Position = position;
	Velocity = vec3(0);
}

Entity::Entity(unsigned char textureIndex, float x, float y)
{
	CurrentChunk = 0;
	TextureIndex = textureIndex;
	Position = vec2(x,y);
	Velocity = vec3(0);
}

Entity& Entity::operator>>(vec3& force)
{
	Velocity += force;
	// TODO: insert return statement here
	return *this;
}

Entity& Entity::operator>>(vec2& force)
{
	Position += force;
	// TODO: insert return statement here
	return *this;
}
