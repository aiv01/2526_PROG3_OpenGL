#version 460 core

in vec2 vert_uv_out;

//layout (binding = 1) uniform sampler2D tv_tex; //not used anymore
uniform float time;

out vec4 frag_color;

float rand(vec2 co)
{
    return fract(sin(dot(co.xy, vec2(12.9898,78.233))) * 43758.5453); //source https://gist.github.com/yiwenl/dbbaa48e1bc8efd3d89a
}

void main() 
{

     //vec4 base = texture(tv_tex, vert_uv_out); //not used anymore

     // genera noise per pixel
     float noise = rand(vert_uv_out * 800.0 + time*5);

     // grayscale
     vec3 noiseColor = vec3(noise);

     frag_color = vec4(noiseColor, 1.0);
   
}