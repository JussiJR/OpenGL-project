#pragma once
#ifndef __entity_h_
#define __entity_h_
#pragma pack(1)
#include <glm/matrix.hpp>

using namespace glm;

class Entity{
public:
	float Velocity;
	lowp_mat4x4 ModelMatrix;
	Entity();
};
#pragma pack(pop)
#endif

