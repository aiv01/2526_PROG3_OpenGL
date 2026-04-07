#version 460 core

in vec2 vert_uv_out;
in vec3 vert_world_norm_out;

layout (binding = 0) uniform sampler2D trup_tex;

out vec4 frag_color;

void main() 
{
    //frag_color = texture(trup_tex, vert_uv_out);
    //frag_color = vec4(vert_world_norm_out, 1.f);
    frag_color = vec4(normalize(vert_world_norm_out), 1.f);
    
}