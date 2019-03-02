#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 aTexCoord;

out vec3 Pos;
out vec2 TexCoord;

uniform mat4 model;
uniform mat4 viewprojection;

void main()
{
	gl_Position = viewprojection * model * vec4(position, 1.0f);

	Pos = position.xyz;
	TexCoord = aTexCoord;
}