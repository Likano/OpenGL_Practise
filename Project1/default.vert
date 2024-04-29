#version 330 core

// Positions/ cordinates
layout (location = 0) in vec3 aPos;

// colors
layout (location = 1) in vec3 aColor; 

layout (location = 2) in vec2 aTex;

// outputs the color for the fragment shader
out vec3 color;


out vec2 textCoord;

// controls the scale
uniform float scale;

void main() 
{
	// output the positions of all vertices
	gl_Position = vec4(aPos.x + aPos.x * scale , aPos.y + aPos.y * scale, aPos.z + aPos.z * scale, 1.0);
	
	// control the colors from the vertex data to color
	color = aColor;

	textCoord = aTex;
}