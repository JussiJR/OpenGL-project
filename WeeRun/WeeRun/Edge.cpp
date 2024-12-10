#include "Edge.h"

edge::edge(int link, int texture, int x, int y, int portalLink, int portalChunkIndex)
    : link(link), texture(texture),x(x),y(y), PortallinkIndex(portalLink), PortalLinkChunkIndex(portalChunkIndex)
{
    
}

glm::vec2 edge::Position(void) const
{
    return glm::vec2(x,y);
}

int edge::pack(void) const
{
    return ((texture & 0xF) << 18) | ((y & 0x1FF) << 9) | (x & 0x1FF);
}
