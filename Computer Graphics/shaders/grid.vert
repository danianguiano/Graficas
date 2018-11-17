#version 330

out vec3 InterpolatedColor;

uniform float time;

void main()
{
  float width = 10.0;
  
  float x = mod(gl_VertexID, width);
  float y = floor(gl_VertexID / width);
  
  float u = x / (width - 1.0);
  float v = y / (width - 1.0);
  
  float xOffset = cos(time + y * 0.2) * 0.1;
  float yOffset = cos(time + x * 0.3) * 0.2;
  
  float ux = u * 2.0 - 1.0 + xOffset;
  float vy = v * 2.0 - 1.0 + yOffset;
  
  vec2 xy = vec2(ux, vy) * 1.2;
  
  gl_Position = vec4(xy, 0.0, 1.0);
  gl_PointSize = 20.0;
  InterpolatedColor = vec3(0.0, 0.0, 0.0);
}