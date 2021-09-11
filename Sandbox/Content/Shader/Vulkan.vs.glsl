#version 450 core

layout(location = 0) in vec3 in_position;
layout(location = 1) in vec3 in_normal;
layout(location = 2) in vec2 in_texcoord;

layout(location = 0) out vec3 out_color;
layout(location = 1) out vec2 out_texcoord;

layout(push_constant) uniform constants
{
	mat4 test;
} PushConstants;

layout(set = 0, binding = 0) uniform ModelData
{
	mat4 viewProjectionMatrix;
} model;

void main()
{
    gl_Position = model.viewProjectionMatrix * vec4(in_position, 1.0);
    out_color = in_normal;
    out_texcoord = in_texcoord;
}