
varying out vec4 pos;


void main()
{
    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
    pos = gl_ModelViewMatrix * gl_Vertex;

    // transform the texture coordinates
    gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;

    gl_FrontColor = gl_Color;

}