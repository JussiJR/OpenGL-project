#version 430

in vec2 TextCoord;  // Receive texture coordinates from the vertex shader
out vec4 fragColor;
uniform sampler2D tex;

void main() {
    fragColor = texture(tex, TextCoord);  // Sample the texture using the passed coordinates
}
