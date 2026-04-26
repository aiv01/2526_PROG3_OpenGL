#version 460 core

layout (location = 0) in vec3 vert_pos;
layout (location = 1) in vec2 vert_uv;
layout (location = 2) in vec3 vert_norm;

uniform mat4 mvp;
uniform mat4 model;

out vec2 vert_uv_out;
out vec3 vert_world_pos_out;
out vec3 vert_world_norm_out;

void main() 
{
    /*
    gl_Position = mvp * vec4(vert_pos, 1.f);
    vert_uv_out = vert_uv;
    //vert_world_norm_out = vert_norm;
    
    //vert_world_norm_out = mat3(model) * vert_norm;
    // Mrot: Transp(M) = Inver(M) => M = Transp(Inver(M))
    vert_world_norm_out = mat3(transpose(inverse(model))) * vert_norm;
*/

    vec4 world_pos = model * vec4(vert_pos, 1.0);
    gl_Position = mvp * vec4(vert_pos, 1.0);
    vert_uv_out = vert_uv;
    vert_world_pos_out = world_pos.xyz;
    vert_world_norm_out = mat3(transpose(inverse(model))) * vert_norm;
}
