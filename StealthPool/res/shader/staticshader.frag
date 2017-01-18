
uniform sampler2D texture;
uniform vec2 playerPosition;

in vec4 pos;

void main()
{
    vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);

    gl_FragColor = gl_Color * pixel;

	//gl_FragColor.rgb *= 40.0 / (length(playerPosition.xy - pos.xy) + 0.5) + <ambient color>;
	gl_FragColor.rgb *= 40.0 / (length(playerPosition.xy - pos.xy) + 0.5) - 0.1;
}