
#ifndef __vectorpoint_h__
#pragma once
#pragma pack(1)

#define __vectorpoint_h__


typedef struct VectorPoint {
	unsigned long long index : 6;
	unsigned long long Normal : 3;
	unsigned long long connection : 6;
	unsigned long long textureIndex : 6;
	unsigned long long floorHeight : 8;
	unsigned long long portalheight : 8;
	unsigned long long roofHeight : 8;
	unsigned long long positionX : 9;
	unsigned long long positionY : 9;

};
#pragma pack(pop)
#endif