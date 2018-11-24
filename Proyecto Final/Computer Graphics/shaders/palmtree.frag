#version 330

out vec4 FragColor;

uniform vec2 iResolution;
uniform float iTime;

void main()
{
    vec2 p = gl_FragCoord.xy / iResolution.xy;
    vec2 q = p - vec2(0.35, 0.7);
    
    vec3 color = mix(vec3(1.0, 0.4, 0.1),
                     vec3(1.0, 0.8, 0.3),
                     sqrt(p.y));
    
    float r = 0.2;
    r += 0.1 * cos(atan(q.y, q.x) * 10.0 + 
                   20.0 * (cos(iTime) * 0.25 + 0.75) * q.x + 1.0);
    color *= smoothstep(r, r + 0.01, length(q));
    
    r = 0.015;
    r += 0.002 * cos(120.0 * q.y);
    r += exp(-40.0 * p.y);
    color *= 1.0 - 
        (1.0 - 
         smoothstep(r, r + 0.002, 
                    abs(q.x - 0.25 * sin(2.0 * q.y)))) * 
        (1.0 - 
         smoothstep(0.0f, 0.01, q.y));
    
    FragColor = vec4(color, 1.0);
}