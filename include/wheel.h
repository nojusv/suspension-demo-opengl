#include <glad/glad.h>
#include <vector>
#include <glm/glm.hpp>

class Wheel
{
private:
	GLuint vao = 0, vbo = 0;
	std::vector<glm::vec2> wheel_verts;
public:
	void setup_wheel();
	const GLuint get_vao();
	const size_t get_wheel_verts_size();
};