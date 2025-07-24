#pragma once
#include <glad/glad.h>
#include <vector>
#include <glm/glm.hpp>

constexpr auto SEGMENT_SAMPLES = 20;

// track will have a little flat platform the wheel will spawn onto
constexpr auto TRACK_STARTING_HEIGHT = 100.f;
constexpr auto TRACK_STARTING_WIDTH = 300.f;

class Track 
{
private:
	GLuint vao = 0, vbo = 0;
	std::vector<glm::vec2> verts;
	void sample_spline(const std::vector<glm::vec2>& track_points);
	glm::vec2 catmull_rom(const glm::vec2& p0, const glm::vec2& p1, const glm::vec2& p2, const glm::vec2& p3, float t);
public:
	void setup_track();
	const GLuint get_vao();
	const size_t get_verts_size();
};