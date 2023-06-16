#pragma once
#include <GL/glew.h>
#include <glm.hpp>

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class Shader
{
public:
	// constructor generates the shaderStencilTesting on the fly
	// ------------------------------------------------------------------------
	Shader(const char* vertexPath, const char* fragmentPath);

	~Shader();

	// activate the shaderStencilTesting
	// ------------------------------------------------------------------------
	void Use() const;

	unsigned int GetID() const;

	// MVP
	unsigned int loc_model_matrix;
	unsigned int loc_view_matrix;
	unsigned int loc_projection_matrix;

	// utility uniform functions
	void SetInt(const std::string& name, int value) const;

	void SetFloat(const std::string& name, float value) const;

	void SetVec3(const std::string& name, const glm::vec3& value) const;

	void SetVec3(const std::string& name, float x, float y, float z) const;

	void SetMat4(const std::string& name, const glm::mat4& mat) const;

private:
	void Init(const char* vertexPath, const char* fragmentPath);

	// utility function for checking shaderStencilTesting compilation/linking errors.
	// ------------------------------------------------------------------------
	void CheckCompileErrors(unsigned int shaderStencilTesting, std::string type);
private:
	unsigned int ID;
};

