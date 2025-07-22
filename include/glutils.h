#include <glad/glad.h>
#include <vector>
#include <glm/glm.hpp>

namespace Glutils {
	GLuint setup_vec2_vbo(const std::vector<glm::vec2>& verts);
	GLuint setup_vec2_vao(const GLuint vbo);
}
