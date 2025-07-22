#pragma once
#include <glad/glad.h>
#include <vector>
#include <glm/glm.hpp>

constexpr auto SEGMENT_SAMPLES = 20;

class Track 
{
private:
	GLuint vao = 0, vbo = 0;
	std::vector<glm::vec2> track_verts;
	void sample_spline(const std::vector<glm::vec2>& track_points);
	glm::vec2 catmull_rom(const glm::vec2& p0, const glm::vec2& p1, const glm::vec2& p2, const glm::vec2& p3, float t);
	void setup_vbo();
	void setup_vao();
public:
	void setup_track();
	const GLuint get_vao();
	const size_t get_track_verts_size();
};