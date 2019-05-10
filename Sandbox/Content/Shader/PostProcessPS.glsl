#version 410 core

layout(location = 0) out vec4 color;

in vec2 TexCoord;

uniform sampler2D texture0;

void main()
{
    vec2 coord = TexCoord;
    //coord.x += sin(coord.y * 50) * 0.01; // swirl

    // distort
    vec2 centerd = coord - vec2(0.5, 0.5);
    float dd = dot(centerd, centerd);
    centerd = (centerd * dd) * 0.2 + centerd * 0.8;
    //coord = centerd + vec2(0.5, 0.5);

    color = texture(texture0, coord);

    // fringe
    float m = 0.01;
    color.r = texture(texture0, coord + vec2(m, -m * 0.2) * centerd).r;
    color.g = texture(texture0, coord + vec2(m * 0.2, -m) * centerd).g;
    color.b = texture(texture0, coord + vec2(-m, m * 0.2) * centerd).b;

    //color.rgb = vec3((color.r + color.g + color.b) / 3.0); // b&w
    //color.rgb += ((sin(coord.y * 800) + 1) / 2) * 0.08f; // stripes
    color.rgb *= 1 - (dd / 0.8); // vignette
}