#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "game.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	//glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
}

int main() 
{
	if (!glfwInit())
	{
		std::cout << "Failed to initialise glfw\n";
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// not resizable for now so we dont have to deal with it
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow* window = glfwCreateWindow(800, 800, "Suspension Demo", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to load opengl functions\n";
		glfwTerminate();
		return -1;
	}

	Game game;
	if (!game.init())
	{
		glfwTerminate();
		return -1;
	}

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.529f, 0.808f, 0.922f, 1.0f); // sky blue
		glClear(GL_COLOR_BUFFER_BIT);
		game.draw_track();
		game.draw_wheel();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
