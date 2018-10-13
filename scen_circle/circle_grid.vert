vec2 getCirclePoint(float id, float segments)
{
  float ux = floor(id / 6.0) + mod(id, 2.0);
  float vy = mod(floor(id / 2.0) + floor(id / 3.0), 2.0);
  
  float angle = ux / segments * radians(180.0) * 2.0;
  float radius = vy + 1.0;
  
  float x = radius * cos(angle);
  float y = radius * sin(angle);
  
  return vec2(x, y);
}

void main()
{
  float numSegments = 20.0;
  float pointsPerCircle = numSegments * 6.0;
  float circleId = floor(vertexId / pointsPerCircle);
  float circleCount = floor(vertexCount / pointsPerCircle);
  
  float width = floor(sqrt(circleCount));
  
  float x = mod(circleId, width);    // [0, width - 1]
  float y = floor(circleId / width); // [0, 00]
  
  float u = x / (width - 1.0);
  float v = y / (width - 1.0);
  
  float xOffset = cos(time + y * 0.2) * 0.1;
  float yOffset = cos(time + x * 0.3) * 0.2;
  
  float ux = u * 2.0 - 1.0 + xOffset;
  float vy = v * 2.0 - 1.0 + yOffset;
  vec2 xy = getCirclePoint(vertexId, numSegments) * 0.1 + vec2(ux, vy);
  
  gl_Position = vec4(xy, 0.0, 1.0);
  v_color = vec4(1.0, 0.0, 0.0, 1.0);
}