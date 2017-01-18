
uniform sampler2D texture;
uniform vec2 playerPosition;

layout(origin_upper_left) in vec4 gl_FragCoord;

void main()
{
    vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);

    gl_FragColor = gl_Color * pixel;




    vec4 lightColor = 1 + (attenuation[i].y * distance) + (attenuation[i].z * distance * distance);

    vec3 frag_intensity = 30 / (1 + 2 * length(playerPosition.xy - gl_FragCoord.xy) + 3*pow(length(playerPosition.xy - gl_FragCoord.xy),2));


	//gl_FragColor.rgb *= 30.0 / (length(playerPosition.xy - gl_FragCoord.xy) + 0.4) + 0.1;
}