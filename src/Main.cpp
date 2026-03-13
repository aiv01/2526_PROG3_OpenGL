#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdexcept>
#include <string>
#include <format>

int main() 
{
	std::cout << "It' Working" << std::endl;
	
	if (glfwInit() == GLFW_FALSE) 
	{
		throw std::runtime_error("error on glfw initialization!");
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_COMPAT_PROFILE, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);

	GLFWmonitor* Monitor = NULL; //windowed mode
	GLFWwindow* Window = glfwCreateWindow(800, 600, "Hello OpenGL", Monitor, NULL);
	if (Window == NULL) 
	{
		throw std::runtime_error("error on creating the window!");
	}

	glfwMakeContextCurrent(Window);

	if (gladLoadGL(glfwGetProcAddress) == 0) 
	{
		throw std::runtime_error("error on loading GL functions!");
	}

	// Control VSync: 0 = disable, 1 = enabled.
	//glfwSwapInterval(1);  //default

	while(!glfwWindowShouldClose(Window)) 
	{
		static float LastTime = glfwGetTime();
		float CurrentTime = glfwGetTime();
		float DeltaTime = CurrentTime - LastTime;
		LastTime = CurrentTime;

		static float TitleUpdateMaxTime = 1.f;
		static float TitleUpdateElapsed = 0.f;

		TitleUpdateElapsed += DeltaTime;
		if (TitleUpdateElapsed >= TitleUpdateMaxTime) 
		{
			int Fps = 1.f / DeltaTime;
			std::string Title = std::format("OpenGL App | DeltaTime: {} - FPS: {}", DeltaTime, Fps);
			glfwSetWindowTitle(Window, Title.c_str());
			TitleUpdateElapsed -= TitleUpdateMaxTime;
		}
		
		
		glfwSwapBuffers(Window);
		glfwPollEvents();
	}

	return 0;	
}