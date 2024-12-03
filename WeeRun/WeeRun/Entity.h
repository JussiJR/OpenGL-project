#pragma once
#ifndef __entity_h_
#define __entity_h_
#pragma pack(1)
#include <glm/matrix.hpp>

using namespace glm;

class Entity{
private:


public:
	vec3 Velocity;
	vec3 Position;
	unsigned char TextureIndex;
	Entity();
};
#pragma pack(pop)
#endif

