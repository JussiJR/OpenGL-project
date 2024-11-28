#version 460 core


//	View matrix
uniform mat4 view;

//	Output coord
out vec2 TextCoord;

//	Map data
layout(std430 ,binding = 0) readonly buffer ssbo1{
	uint map[];
};

//	Data about offsets
layout(std430) buffer ubo1{
uint[] offsets;
};


void main(){

	

	vec4 world;
	gl_Position  = view * world;

}