#version 330 core
out vec4 FragColor

in vec3 Normal;
in vec3 FragPos;

uniform vec3 lightPos;
uniform vec3 viewPos;
uniform vec3 lightColor;
uniform vec3 objectColor;

void m,ain()
{
	FragColor = vec4(objectColor, 1.0);
}