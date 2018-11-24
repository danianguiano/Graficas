#version 330

in vec2 textCoords;

out vec4 FragColor;

uniform sampler2D DiffuseTexture;

void main()
{	
	FragColor = texture2D(DiffuseTexture, textCoords);
}