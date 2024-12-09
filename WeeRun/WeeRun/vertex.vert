// Vertex shader's Version
#version 460 core
//Defines
#define EXTRACT_POSITION_Z  uint((edge >> 10) & 7); 
#define EXTRACT_POSITION_X  uint((edge >> 17) & 7); 
#define EXTRACT_TEXTURE (edge >> 24) & 15;

// OpenGL Instancing tricking part
layout(location = 0) float y; 
//	mvp
uniform mat4 u_view;
uniform mat4 u_projection;

//	Output coord
out vec2 TextCoord;

//	edge data
layout(std430 ,binding = 0) readonly buffer ssbo1{
	uint edges[];
};

void main(){	

	// Textures 
	const vec2 texturePosition[16] = {
		vec2(0),
		vec2(0),
		vec2(0),
		vec2(0),
		vec2(0),
		vec2(0),
		vec2(0),
		vec2(0),
		vec2(0),
		vec2(0),
		vec2(0),
		vec2(0),
		vec2(0),
		vec2(0),
		vec2(0),
		vec2(0)
	};
	//varialbes needed
	vec3 position;
	vec2 offset;

	// Set offsets
	offset.x = mod(gl_VertexID,2);
	offset.y = floor(gl_VertexID * 0.5) - gl_InstanceID;
	// extract data from map
	uint edge = edges[uint(gl_InstanceID + gl_InstanceID+offset)]; 
	uint edge_texture = EXTRACT_TEXTURE;

	// set position
	position.x = EXTRACT_POSITION_X;
	position.y = y; 
	position.z = EXTRACT_POSITION_Z;

	// set texture coordinate
	TextCoord = (offset * 32) + texturePosition[edge_texture];
	
	// set position of vertex
	gl_Position  = u_view * u_projection * vec4(position,1);
}