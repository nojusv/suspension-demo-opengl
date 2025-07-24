#include "game.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include <iostream>
bool Game::init()
{
	shader_program = create_shader_program();

	if (!shader_program) return false;

	proj_matrix = glm::ortho(
		0.0f, static_cast<float>(WINDOW_WIDTH),
		0.0f, static_cast<float>(WINDOW_HEIGHT),
		-1.0f, 1.0f                                      
	);

	track.setup_track();
	wheel.setup_wheel();

	return true;
}

void Game::draw_track()
{
	glUseProgram(shader_program);

	glUniform3f(glGetUniformLocation(shader_program, "track_color"), .2f, 1.f, .4f); // Grassy green
	
	glUniformMatrix4fv(glGetUniformLocation(shader_program, "model"), 1, GL_FALSE, glm::value_ptr(glm::mat4(1.0f)));
	glUniformMatrix4fv(glGetUniformLocation(shader_program, "view"), 1, GL_FALSE, glm::value_ptr(glm::mat4(1.0f)));
	glUniformMatrix4fv(glGetUniformLocation(shader_program, "projection"), 1, GL_FALSE, glm::value_ptr(proj_matrix));

	glBindVertexArray(track.get_vao());

	glDrawArrays(GL_TRIANGLE_STRIP, 0, track.get_verts_size());

	glBindVertexArray(0);
}

void Game::draw_wheel()
{
	glUseProgram(shader_program);

	glUniform3f(glGetUniformLocation(shader_program, "track_color"), 0.f, 0.f, 0.f); // black

	glm::mat4 model_matrix = glm::translate(glm::mat4(1.f), glm::vec3(wheel.get_pos(), 0.f));

	glUniformMatrix4fv(glGetUniformLocation(shader_program, "model"), 1, GL_FALSE, glm::value_ptr(model_matrix));
	glUniformMatrix4fv(glGetUniformLocation(shader_program, "view"), 1, GL_FALSE, glm::value_ptr(glm::mat4(1.0f)));
	glUniformMatrix4fv(glGetUniformLocation(shader_program, "projection"), 1, GL_FALSE, glm::value_ptr(proj_matrix));

	glBindVertexArray(wheel.get_vao());

	glDrawArrays(GL_TRIANGLE_FAN, 0, wheel.get_verts_size());

	glBindVertexArray(0);
}