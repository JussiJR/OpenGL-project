#ifndef __entity_h__
#pragma once
#pragma pack(1)


#define __entity_h__

#include "transform.h"

typedef struct Entity {
	Transform transform;				
	unsigned char baseSpeed : 5;			// Base speed of the entity
	unsigned char Texture : 3;				// Texture what entity has
	unsigned char Chunk;					// Chunk where entity is in
} Entity;

#pragma pack(pop)
#endif
