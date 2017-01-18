
uniform sampler2D texture;
uniform vec2 playerPosition;

layout(origin_upper_left) in vec4 gl_FragCoord;

void main()
{
    // lookup the pixel in the texture
    vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);

    // multiply it by the color
    gl_FragColor = gl_Color * pixel;

	gl_FragColor.rgb *= 30.0 / (length(playerPosition.xy - gl_FragCoord.xy) + 0.4) + 0.1;
	//if(gl_FragColor.a > 0.0f) gl_FragColor.a = 1;
}