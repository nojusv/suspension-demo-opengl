#pragma once
#include "track.h"

constexpr auto WINDOW_WIDTH = 800;
constexpr auto WINDOW_HEIGHT = 800;

class Game
{
private:
	glm::mat4 proj_matrix;
	GLuint shader_program = 0;
	Track track;
public:
	bool init();
	void draw_track();
};