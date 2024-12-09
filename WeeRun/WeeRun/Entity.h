#pragma once
#ifndef __entity_h_
#define __entity_h_
#include <glm/matrix.hpp>

using namespace glm;

class Entity{
private:


public:
	unsigned char CurrentChunk;

	/// <summary>
	/// Velocity of entity
	/// </summary>
	vec3 Velocity;

	/// <summary>
	/// Position of entity
	/// </summary>
	vec2 Position;

	/// <summary>
	/// Texture index
	/// </summary>
	unsigned char TextureIndex;

	Entity() {};

	/// <summary>
	/// Constructor with only texture ( sets ithers to 0)
	/// </summary>
	/// <param name="textureIndex">index of the texture in texture map</param>
	Entity(unsigned char textureIndex);

	/// <summary>
	/// Constructor with texture indexes and position vec2
	/// </summary>
	/// <param name="textureIndex">index of the texture in texture map</param>
	/// <param name="position">Position of entity on spawnposition</param>
	Entity(unsigned char textureIndex, vec2 position);

	/// <summary>
	/// Constructor 
	/// </summary>
	/// <param name="textureIndex">index of the texture in texture map</param>
	/// <param name="x">x float of X position for entity</param>
	/// <param name="y">y float of Y position for entity</param>
	Entity(unsigned char textureIndex,float x,float y);

	/// <summary>
	/// Fast input velocity
	/// </summary>
	/// <param name="force">added velocity</param>
	/// <returns>Entity with applied velocity</returns>
	Entity& operator>>(vec3& force);

	/// <summary>
	/// Fast input position addition
	/// 
	/// </summary>
	/// <param name="force">position values to be added</param>
	/// <returns>Entity with applied positiion addition</returns>
	Entity& operator>>(vec2& force);
};
#endif

