#version 460 core

in vec2 vert_uv_out;
in vec3 vert_world_pos_out;
in vec3 vert_world_norm_out;

layout (binding = 0) uniform sampler2D trup_tex;

uniform vec3 light_pos;
uniform vec3 view_pos;

out vec4 frag_color;



void main() 
{

    /*
    //frag_color = texture(trup_tex, vert_uv_out);
    //frag_color = vec4(vert_world_norm_out, 1.f);
    frag_color = vec4(normalize(vert_world_norm_out), 1.f);
    */
    vec3 albedo = texture(trup_tex, vert_uv_out).rgb;

    vec3 N = normalize(vert_world_norm_out);
    vec3 L = normalize(light_pos - vert_world_pos_out);
    vec3 V = normalize(view_pos - vert_world_pos_out);
    vec3 R = reflect(-L, N);

    // ambient
    vec3 ambient = 0.15 * albedo;

    // diffuse
    float diff = max(dot(N, L), 0.0);
    vec3 diffuse = diff * albedo;

    // specular
    float spec = pow(max(dot(V, R), 0.0), 32.0);
    vec3 specular = vec3(1.0) * spec;
    vec3 finalColor = ambient + diffuse + specular;
    frag_color = vec4(finalColor, 1.0);


}