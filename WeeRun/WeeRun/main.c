/**
*  _____                                                 _____
* ( ___ )                                               ( ___ )
*  |   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|   |
*  |   | ############################################### |   |
*  |   | ##███╗###███╗#█████╗#██╗███╗###██╗####██████╗## |   |
*  |   | ##████╗#████║██╔══██╗██║████╗##██║###██╔════╝## |   |
*  |   | ##██╔████╔██║███████║██║██╔██╗#██║###██║####### |   |
*  |   | ##██║╚██╔╝██║██╔══██║██║██║╚██╗██║###██║####### |   |
*  |   | ##██║#╚═╝#██║██║##██║██║██║#╚████║██╗╚██████╗## |   |
*  |   | ##╚═╝#####╚═╝╚═╝##╚═╝╚═╝╚═╝##╚═══╝╚═╝#╚═════╝## |   |
*  |   | ############################################### |   |
*  |___|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|___|
* (_____)                                               (_____)
* 
* Main.C file has Main ENTRYPOINT for WeeRun program.
* 
* USED REFERENCES:
*	- https://www.glfw.org/documentation - GLFW Documentation
*	- 
* 
*/


//NOTE: Defines

//	GLFW

//		GLFW custom error hexadecimals
#define GLFW_INITIALIZATION_SELF_FAILURE 0xAAF // GLFW initialization failure.
#define GLFW_INITIALIZATION_WINDOW_FAILURE 0xABF // GLFW Window initialization failure.

//			Window
#define GLFW_WINDOW_SIZE_WIDTH 800 // Window Width
#define GLFW_WINDOW_SIZE_HEIGHT 540 // Widnow Height

//	OpenGL

//		OpenGL custom error hexadecimals
#define OPENGL_INITIALIZATION_SELF_FAILURE 0xBAF // OPENGL initialization failure.


//NOTE: Includes
#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


//NOTE: Typedefs


//NOTE: Methods

//	Main Entry Point.
int main(int argc, char** argv) {
	
	//Initialize GLFW
	if (!glfwInit()) {
		fprintf(stderr, "Error loading glfw");
		return GLFW_INITIALIZATION_SELF_FAILURE;
	}

	//Initialize Window
	GLFWwindow* window = glfwCreateWindow(GLFW_WINDOW_SIZE_WIDTH, GLFW_WINDOW_SIZE_HEIGHT, "Test", NULL, NULL); // Lmao
	if (!window) {
		fprintf(stderr, "Error creating GLFWwindow.");
		glfwTerminate();
		return GLFW_INITIALIZATION_WINDOW_FAILURE;
	}
	
	glfwMakeContextCurrent(window); // glfw Context setup

	//Initialize OpenGL
	if (!gladLoadGL()) {
		fprintf(stderr, "Error loading OpenGL");
		glfwDestroyWindow(window);
		glfwTerminate();
		return OPENGL_INITIALIZATION_SELF_FAILURE;
	}

	//setup OpenGL window 

	glClearColor(0xAF / 0xFF, 0x85 / 0xFF, 0xFF / 0xFF, 0xAF / 0xFF);

	while (!glfwWindowShouldClose(window)) {
		
		//Clear buffers
		glClear(GL_COLOR_BUFFER_BIT);
		
		//Swap front and back buffer
		glfwSwapBuffers(window);

		//Poll events
		glfwPollEvents();
	}
	glfwDestroyWindow(window);
	glfwTerminate();
}

