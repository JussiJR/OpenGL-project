#version 430 core

#define EXTRACT_POSITION_Z  uint((edge >> 14) & 65535)  
#define EXTRACT_POSITION_X  uint(edge & 65535)  
#define EXTRACT_TEXTURE (edge >> 28) & 15

layout(location = 0) float y; 

uniform mat4 u_view;
uniform mat4 u_projection;

out vec2 TextCoord;

layout(std430, binding = 1) readonly buffer ssbo1 {
    uint edges[];
};

void main() {

    vec2 textureCoord;
    vec3 position;
    vec2 offset;

    const uint vertexID = uint(gl_VertexID);
    const uint instanceID = uint(gl_InstanceID);

    offset.x = mod(vertexID, 2);  
    offset.y = (vertexID >> 1) - instanceID;  

    const uint edge = edges[uint((instanceID << 1) + offset.x)];  
    uint edge_texture = EXTRACT_TEXTURE;  

    position.x = EXTRACT_POSITION_X;
    position.y = y;  
    position.z = EXTRACT_POSITION_Z;

    textureCoord.x = float(mod(edge_texture, 4)) * 32.0; 
    textureCoord.y = floor(float(edge_texture >> 2)) * 32.0;

    TextCoord = textureCoord;

    gl_Position = u_view * u_projection * vec4(position, 1.0);
}
