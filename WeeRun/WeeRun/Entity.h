#pragma once
#ifndef __entity_h_
#define __entity_h_
#include <glm/matrix.hpp>
class Entity{
private:

	/// <summary>
	/// Velocity of entity
	/// </summary>
	glm::vec2 Velocity = glm::vec2(0.0f, 0.0f);

public:

	/// <summary>
	/// index of chunk where entity is 
	/// </summary>
	unsigned char CurrentChunk;


	/// <summary>
	/// Texture index
	/// </summary>
	unsigned char TextureIndex;

	/// <summary>
	/// Position of entity
	/// </summary>
	glm::vec2 Position;
	Entity() {
		CurrentChunk = 0;
		Position = glm::vec2(0);
		TextureIndex = 0;
	};

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
	Entity(unsigned char textureIndex, glm::vec2 position);

	/// <summary>
	/// Constructor 
	/// </summary>
	/// <param name="textureIndex">index of the texture in texture map</param>
	/// <param name="x">x float of X position for entity</param>
	/// <param name="y">y float of Y position for entity</param>
	Entity(unsigned char textureIndex,float x,float y);
};
#endif

