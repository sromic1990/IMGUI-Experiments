#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main()
{
	if(!glfwInit())
	{
		return -1;
	}

	//Creating a windowed mode window and its OpenGL context
	GLFWwindow* window = glfwCreateWindow(640, 480, "Hello, World", NULL, NULL);
	if(!window)
	{
		glfwTerminate();
		return -1;
	}

	//Make window's context current
	glfwMakeContextCurrent(window);

	//Initialize GLEW
	if(glewInit() != GLEW_OK)
	{
		return -1;
	}

	//Main Loop
	while(!glfwWindowShouldClose(window))
	{
		//Render here
		glClear(GL_COLOR_BUFFER_BIT);

		//Draw a triangle
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();

		//Swap front and back buffers
		glfwSwapBuffers(window);

		//Poll for and process events
		glfwPollEvents();
	}

	glfwTerminate();

	std::cout << "Hello, World!" << std::endl;

	return 0;
}