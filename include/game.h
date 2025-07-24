#pragma once
#include "track.h"
#include "wheel.h"

constexpr auto WINDOW_WIDTH = 800;
constexpr auto WINDOW_HEIGHT = 800;

class Game
{
private:
	glm::mat4 proj_matrix;
	GLuint shader_program = 0;
	Track track;
	Wheel wheel;
public:
	bool init();
	void draw_track();
	void draw_wheel();
};