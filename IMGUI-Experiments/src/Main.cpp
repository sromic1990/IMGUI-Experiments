#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

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

	//Setup ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;

	//Setup Platform/renderer bindings
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 130");

	//Setup ImGui Style
	ImGui::StyleColorsDark();

	//Main Loop
	while(!glfwWindowShouldClose(window))
	{
		//Poll for and process events
		glfwPollEvents();

		//Start ImGui frame
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		//Create an ImGui window
		ImGui::Begin("Hello, World");
		ImGui::Text("This is some useful text!");
		ImGui::End();

		glClear(GL_COLOR_BUFFER_BIT);

		//Draw a triangle
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();

		//Render ImGui
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		
		//Swap front and back buffers
		glfwSwapBuffers(window);
	}

	//Clean up ImGui
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwTerminate();

	std::cout << "Hello, World!" << std::endl;

	return 0;
}