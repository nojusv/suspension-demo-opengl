#include "track.h"
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <cmath>
#include "glutils.h"

// Uniform catmull rom
glm::vec2 Track::catmull_rom(const glm::vec2& p0, const glm::vec2& p1, const glm::vec2& p2, const glm::vec2& p3, float t)
{
	float t2 = t * t;
	float t3 = t2 * t;

	return 0.5f * (
		(2.f * p1) +
		(-p0 + p2) * t +
		(2.f * p0 - 5.f * p1 + 4.f * p2 - p3) * t2 +
		(-p0 + 3.f * p1 - 3.f * p2 + p3) * t3);
}

void Track::sample_spline(const std::vector<glm::vec2>& track_points)
{
	// need to loop every 4 points 
	for (auto i = 0; i < track_points.size(); i += 4)
	{
		for (auto y = 0; y < SEGMENT_SAMPLES; y++)
		{
			float t = y / static_cast<float>(SEGMENT_SAMPLES);
			// Creating a line to be used with GL_LINE_STRIP
			track_verts.push_back(catmull_rom(track_points[i], track_points[i + 1], track_points[i + 2], track_points[i + 3], t));
		}
	}
}

void Track::setup_track()
{
	for (auto i = 0; i < 100; i++)
	{
		track_verts.emplace_back(i * 12.5f, 0.f);
		track_verts.emplace_back(i * 12.5f, 150.f);
	}

	vbo = Glutils::setup_vec2_vbo(track_verts);
	vao = Glutils::setup_vec2_vao(vbo);
}

const GLuint Track::get_vao()
{
	return vao;
}

const size_t Track::get_track_verts_size()
{
	return track_verts.size();
}
