#ifndef __entity_h__
#pragma once
#pragma pack(1)


#define __entity_h__

#include "transform.h"


typedef struct Entity {
	
	Transform transform;
	short int currentChunk : 5;
	short int baseSpeed : 6;
	short int Texture: 5;

} Entity;

#pragma pack(pop)
#endif
