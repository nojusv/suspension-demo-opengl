#include "game.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"

bool Game::init()
{
	shader_program = create_shader_program();

	if (!shader_program) return false;

	// 2D much easier than 3D ;)
	proj_matrix = glm::ortho(
		0.0f, static_cast<float>(WINDOW_WIDTH),
		0.0f, static_cast<float>(WINDOW_HEIGHT),
		-1.0f, 1.0f                                      
	);

	track.setup_track();
}

void Game::draw_track()
{
	glUseProgram(shader_program);

	glUniform3f(glGetUniformLocation(shader_program, "track_color"), .2f, 1.f, .4f); // Grassy green
	
	glm::mat4 view_matrix = glm::mat4(1.0f);
	glUniformMatrix4fv(glGetUniformLocation(shader_program, "view"), 1, GL_FALSE, glm::value_ptr(view_matrix));
	glUniformMatrix4fv(glGetUniformLocation(shader_program, "projection"), 1, GL_FALSE, glm::value_ptr(proj_matrix));

	glBindVertexArray(track.get_vao());

	glDrawArrays(GL_TRIANGLE_STRIP, 0, track.get_track_verts_size());

	glBindVertexArray(0);
}