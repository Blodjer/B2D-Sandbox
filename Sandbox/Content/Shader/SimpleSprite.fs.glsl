#version 450 core

layout(location = 0) out vec4 color;

layout(location = 0) in vec3 Pos;
layout(location = 1) in vec2 TexCoord;

layout(binding = 0) uniform sampler2D texture0;

void main()
{
    color = texture(texture0, TexCoord);
}