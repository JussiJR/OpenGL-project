#pragma once
#ifndef __edge_h_
#define __edge_h_

#include <glm/matrix.hpp>


class edge {
public:
	unsigned int PortallinkIndex : 4;
	unsigned int PortalLinkChunkIndex : 4;
	unsigned int y : 9;
	unsigned int x : 9;
	unsigned int texture : 4;
	unsigned char link : 5;
	edge(int link, int texture, int x, int y, int portalLink, int portalChunkIndex);
	edge() : PortallinkIndex(0), PortalLinkChunkIndex(0), x(0), y(0), texture(0), link(0){}
	glm::vec2 Position(void) const;
	int pack(void) const;
};

#endif