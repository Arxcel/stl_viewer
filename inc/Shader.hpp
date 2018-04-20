//
// Created by Arxcel on 4/19/18.
//

#ifndef BASIC_RAY_TRACER_SHADER_HPP
#define BASIC_RAY_TRACER_SHADER_HPP

#include <string>
#include "glew.h"
#include "Transform.hpp"

class Shader {
public:
	Shader(std::string const &filename);
	virtual ~Shader();
	void update(Transform const &transform);
	std::string loadShader(std::string const &path);
	void checkShaderError(GLuint shader, GLuint flag, bool isProgram, std::string const &err_message);
	GLuint createShader(std::string const &text, GLenum shaderType);
	void Bind();
private:
	static const unsigned int NUM_SHADERS = 2;
	Shader(Shader const &) {};
	Shader &operator=(Shader const &){ return *this;}
	enum {
		TRANSFORM_U,
		NUM_UNIFORMS
	};
	GLuint _prog;
	GLuint _shaders[NUM_SHADERS];
	GLint _uniforms[NUM_UNIFORMS];
};


#endif //BASIC_RAY_TRACER_SHADER_HPP
