#version 330 core
out vec4 FragColor;

in vec3 Normal;  
in vec3 FragPos;  
  
uniform float Ka;
uniform float Kd;
uniform float Ks;
uniform float diff;
uniform float viewDir;
uniform float reflectDir;
uniform float n;

uniform vec3 norm;
uniform vec3 lightDir;
uniform vec3 lightPos; 
uniform vec3 fragPos; 
uniform vec3 viewPos; 
uniform vec3 lightColor;
uniform vec3 objectColor;

void main()
{
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = Kd * max(dot(norm, lightDir), 0.0);
    vec3 ambient = Ka * lightColor;
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);

    float spec = Ks * pow(max(dot(viewDir, reflectDir), 0.0), n);
    vec3 result = (ambient + diff + spec) * objectColor;
    FragColor = vec4(result, 1.0);
}