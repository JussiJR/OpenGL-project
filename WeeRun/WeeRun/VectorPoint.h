
#ifndef __vectorpoint_h__
#pragma once
#pragma pack(1)

#define __vectorpoint_h__


typedef struct VectorPoint {
	int portalwidth : 5;
	int index : 4;
	int Normal : 3;
	int connection : 4;
	int PortalRoomIndex : 8;
	int textureIndex : 5;
	int PointFlags : 3;
	unsigned char position[2];
	short int floorHeight : 5;
	short int portalheight : 5;
	short int roofHeight : 5;
};
#pragma pack(pop)
#endif