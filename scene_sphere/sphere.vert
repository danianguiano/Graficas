#version 330 core

out vec3 InterpolatedColor;

uniform float time;

void main()
{
  float angulo = radians(mod(floor(gl_VertexID / (160.0 / 4.0)) * 4.0, 300.0));
  float angulo2 =  radians(mod(gl_VertexID * 4.0, 150.0));
  
  vec3 vector = vec3(x, y, z);

  float x = sin(angulo2) * cos(angulo);
  float y = sin(angulo2) * sin(angulo);
  float z = cos(angulo2);

  mat4 matriz1 = mat4(1.0);
  matriz1[0][0] = cos(time);
  matriz1[1][0] = -sin(time);
  matriz1[0][1] = sin(time);
  matriz1[1][1] = cos(time);
  
  mat4 matriz2 = mat4(1.0);
  matriz2[1][1] = cos(time);
  matriz2[2][1] = -sin(time);
  matriz2[1][2] = sin(time);
  matriz2[2][2] = cos(time);
  
  gl_Position = matriz1 * matriz2 * vec4(vector, 1.0);
  gl_PointSize = 2.0;
  InterpolatedColor = vec3(1.0, 0.0, 0.0);
}