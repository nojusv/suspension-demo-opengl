#include <glad/glad.h>
#include <vector>
#include <glm/glm.hpp>

constexpr auto PI = 3.14159265359f;
constexpr auto WHEEL_SEGMENTS = 30;
constexpr auto RADIUS = 30.f;

class Wheel
{
private:
	glm::vec2 pos;
	GLuint vao = 0, vbo = 0;
	std::vector<glm::vec2> verts;
public:
	Wheel();
	void setup_wheel();
	GLuint get_vao();
	size_t get_verts_size();
	glm::vec2 get_pos();
};