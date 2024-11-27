#version 460 core

uniform mat4 view;

out vec2 TextCoord;
layout(std430 ,binding = 0) readonly buffer ssbo1{
	uint map[];
};

void main(){

	vec4 world;
	gl_Position  = view * world;

}