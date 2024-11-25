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
* SUMMARY: 
* 
* Main.C file has Main ENTRYPOINT for WeeRun program.
* 
* 
* 
* KNOWN ISSUES:
*	- NoN
* 
* METHODS:
*	- int : main (int,char**)
*		# Definition:
*			## Summary:
*				Main Entry point of a program
*			## Parameters:
*				- int argc : argument count
*				- char** argv : argument vector
*			## Returns:
*				zero on successful run otherwise Error Hexadecimal
*		# Known Issues:
*			- NoN
*		# Note:
*			Propably most modified method of all time
*
* 
* USED REFERENCES:
*	- https://www.glfw.org/documentation - GLFW Documentation
*	- https://www.opengl.org/ - OpenGL Documentation
*	- https://gist.github.com/RabaDabaDoba/145049536f815903c79944599c6f952a - ANSII Color codes 
*	- https://www.ibm.com/docs/en/i/7.4?topic=functions-main-function - Info about Main method
* 
*/


//!NOTE: Defines



//!	GLFW

//!		GLFW custom error hexadecimals
#define GLFW_INITIALIZATION_SELF_FAILURE -2735 // GLFW initialization failure.
#define GLFW_INITIALIZATION_WINDOW_FAILURE -2751 // GLFW Window initialization failure.

//!			Window
#define GLFW_WINDOW_SIZE_WIDTH 800 // Window Width
#define GLFW_WINDOW_SIZE_HEIGHT 540 // Widnow Height

//!	OpenGL

//!		OpenGL custom error hexadecimals
#define OPENGL_INITIALIZATION_SELF_FAILURE -2991 // OPENGL initialization failure.

//!		OpenGL Clear Color

//			Red
#define OPENGL_CLEAR_COLOR_RED 0xAC						// OpenGL clear RGB red
#define OPENGL_NORMALIZED_CLEAR_COLOR_RED 0.67450f		// OpenGL clear RGB red normalized

//			Green
#define OPENGL_CLEAR_COLOR_GREEN 0x82					// OpenGL clear RGB green
#define OPENGL_NORMALIZED_CLEAR_COLOR_GREEN 0.50980f	// OpenGL clear RGB green normalized

//			Blue
#define OPENGL_CLEAR_COLOR_BLUE 0xFF					// OpenGL clear RGB blue
#define OPENGL_NORMALIZED__CLEAR_COLOR_BLUE 1.0f		// OpenGL clear RGB blue normalized

//			Alfa
#define OPENGL_CLEAR_COLOR_ALFA 0xAB					// OpenGL clear RGB alfa
#define OPENGL_NORMALIZED_CLEAR_COLOR_ALFA 0.67058f		// OpenGL clear RGB alfa normalized

//!	Miscs

//!		Color codes

//			Colors
#define COLOR_CODE_RED "\e[0;31m"			// Red
#define COLOR_CODE_YELLOW "\e[0;33m"		//Yellow


//			Reset
#define COLOR_CODE_RESET "\e[0m"



#ifdef _DEBUG
//!		Debugging

//			Debug Logs
#define CONSOLE_LOG_ERROR(message) fprintf(stderr,COLOR_CODE_RED message COLOR_CODE_RESET)			// Error log
#define CONSOLE_LOG_WARNING(message) fprintf(stderr, COLOR_CODE_YELLOW message COLOR_CODE_RESET)	// Warning log



#endif

//!NOTE: Includes
#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


//!NOTE: Typedefs


//!NOTE: Methods

//!	Main Entry Point.
int main(int argc, char** argv) {


	//! Initialize GLFW
	if (!glfwInit()) {
#ifdef _DEBUG
		CONSOLE_LOG_ERROR("Failed to load GLFW.");
#endif // _DEBUG
		return GLFW_INITIALIZATION_SELF_FAILURE;
	}

	//! Initialize Window
	GLFWwindow* window = glfwCreateWindow(GLFW_WINDOW_SIZE_WIDTH, GLFW_WINDOW_SIZE_HEIGHT, "Test", NULL, NULL); // Lmao
	if (!window) {
#ifdef _DEBUG
		CONSOLE_LOG_ERROR("Failed to create Window.");
#endif // _DEBUG
		glfwTerminate();
		return GLFW_INITIALIZATION_WINDOW_FAILURE;
	}
	
	//! glfw Context setup
	glfwMakeContextCurrent(window); 
	
	//! Initialize OpenGL
	if (!gladLoadGL()) {
#ifdef _DEBUG
		CONSOLE_LOG_ERROR("Failed to load OpenGL methods");
#endif // _DEBUG
		glfwDestroyWindow(window);
		glfwTerminate();
		return OPENGL_INITIALIZATION_SELF_FAILURE;
	}

	//! setup OpenGL window 
	glClearColor(OPENGL_NORMALIZED_CLEAR_COLOR_RED,OPENGL_NORMALIZED_CLEAR_COLOR_GREEN,
		OPENGL_NORMALIZED__CLEAR_COLOR_BLUE,OPENGL_NORMALIZED_CLEAR_COLOR_ALFA);


	//! Main Loop
	while (!glfwWindowShouldClose(window)) {
		
		//! Clear buffers
		glClear(GL_COLOR_BUFFER_BIT);

		
		
		//! Swap front and back buffer
		glfwSwapBuffers(window);

		//! Poll events
		glfwPollEvents();
	}



	//! GLFW clean up
	glfwDestroyWindow(window);
	glfwTerminate();
}

