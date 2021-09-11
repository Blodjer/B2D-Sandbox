#version 450 core

#extension GL_ARB_separate_shader_objects : enable

layout(location = 0) in vec3 in_color;
layout(location = 1) in vec2 in_texcoord;

layout(location = 0) out vec4 out_color;

layout(set = 0, binding = 2) uniform FrameInfo
{
	float r;
	float g;
	float b;
} ubo2;

void main()
{
    out_color = vec4(ubo2.r, ubo2.g, ubo2.b, 1) * dot(in_color, vec3(0,0,1));
}