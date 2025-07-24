#include "wheel.h"
#include "glutils.h"
#include "track.h"

Wheel::Wheel()
{
	pos = {static_cast<float>(3 * RADIUS), static_cast<float>(TRACK_STARTING_HEIGHT + RADIUS)};
}

void Wheel::setup_wheel()
{
	verts.emplace_back(0.f, 0.f);

	float two_pi = 2.f * PI;

	for (int i = 0; i <= WHEEL_SEGMENTS; i++)
	{
		float angle = (two_pi * i) / WHEEL_SEGMENTS;
		verts.emplace_back(
			static_cast<float>(RADIUS * sin(angle)),
			static_cast<float>(RADIUS * cos(angle))
		);

	}

	vbo = Glutils::setup_vec2_vbo(verts);
	vao = Glutils::setup_vec2_vao(vbo);
}

size_t Wheel::get_verts_size()
{
	return verts.size();
}

glm::vec2 Wheel::get_pos()
{
	return pos;
}

GLuint Wheel::get_vao()
{
	return vao;
}
