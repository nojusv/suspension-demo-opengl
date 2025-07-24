#include "shader.h"
#include <iostream>

const char* vert_shader_src = R"(
	#version 330 core

	uniform mat4 model;
    uniform mat4 view;
    uniform mat4 projection;

    in vec2 position;

    void main() {
        gl_Position = projection * view * model * vec4(vec3(position, 1.0), 1.0);
    }
)";

const char* frag_shader_src = R"(
    #version 330 core
    out vec4 frag_color;

    uniform vec3 track_color;

    void main() {
        frag_color = vec4(track_color, 1.0);
    }
)";

GLuint create_shader_program()
{
	GLuint shader_program = 0;
	GLint success;

	GLuint vert_shader = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(vert_shader, 1, &vert_shader_src, nullptr);
	glCompileShader(vert_shader);

	glGetShaderiv(vert_shader, GL_COMPILE_STATUS, &success);

	if (success == GL_FALSE)
	{
		std::cout << "Failed to compile vertex shader.\n";
		glDeleteShader(vert_shader);
		return shader_program;
	}

	GLuint frag_shader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(frag_shader, 1, &frag_shader_src, nullptr);
	glCompileShader(frag_shader);

	glGetShaderiv(frag_shader, GL_COMPILE_STATUS, &success);

	if (success == GL_FALSE)
	{
		std::cout << "Failed to compile fragment shader.\n";
		glDeleteShader(vert_shader);
		glDeleteShader(frag_shader);
		return shader_program;
	}

	shader_program = glCreateProgram();
	glAttachShader(shader_program, vert_shader);
	glAttachShader(shader_program, frag_shader);

	glLinkProgram(shader_program);

	glDeleteShader(vert_shader);
	glDeleteShader(frag_shader);

	glGetProgramiv(shader_program, GL_LINK_STATUS, &success);

	if (!success)
	{
		std::cout << "Failed to link shader program\n";
	}

	return shader_program;
}