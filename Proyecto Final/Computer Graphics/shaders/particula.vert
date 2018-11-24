#version 330

in vec3 VertexPosition;
in vec2 VertexTextCoord;

out vec2 textCoords;

uniform mat4 mModelo;
uniform mat4 mVista;
uniform mat4 mProyeccion;

void main()
{
	textCoords = VertexTextCoord;

	mat4 ModelView = mVista * mModelo;

	// Column 0:
	ModelView[0][0] =1;
	ModelView[0][1] =0;
	ModelView[0][2] =0;

	// Column 1:
	ModelView[1][0] = 0;
	ModelView[1][1] = 1;
	ModelView[1][2] = 0;

	// Column 2:
	ModelView[2][0] = 0;
	ModelView[2][1] = 0;
	ModelView[2][2] = 1;

	gl_Position = mProyeccion * ModelView * vec4(VertexPosition, 1.0f);


}