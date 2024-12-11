#version 460 core

in vec2 TextCoord;
out vec4 fragColor;
uniform sampler2D tex;

void main(){
	vec2 outTC = TextCoord / 512;
	fragColor = texture(tex,outTC);
}