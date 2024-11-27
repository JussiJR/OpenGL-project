#include "main.h"

//!	Namespace usages
using namespace std;

//!	Methods
//!		Main
int main(int argc, char** argv){
#ifdef _DEBUG
	//!	Check versions
	//!		GLFW
	printf("Compiled against GLFW %i.%i.%i\n",
		GLFW_VERSION_MAJOR,
		GLFW_VERSION_MINOR,
		GLFW_VERSION_REVISION);
#endif
	//!	Initialization
	//!		GLFW
	//!			Hints
	glfwInitHint(GLFW_JOYSTICK_HAT_BUTTONS, GLFW_FALSE);

	//!			Base

	if (!glfwInit()) {
#ifdef _DEBUG
		return glfwGetError(NULL);
#else
		return EXCEPTIONS_GLFW_INITIALIZATION_GLFWINIT;
#endif
	}


	//!			Window hints
#ifndef _DEBUG
	//!				Window's borders
	glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);

	//!				Window's always on top
	glfwWindowHint(GLFW_FLOATING, GLFW_TRUE);

	//!				Window's debuggability off
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);

#else
	//!				Window's debuggability on
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);

#endif
	//!				Window's resizability
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	
	//!				Window's auto iconifying
	glfwWindowHint(GLFW_AUTO_ICONIFY, GLFW_TRUE);

	//!				Window's context release behavior
	glfwWindowHint(GLFW_CONTEXT_RELEASE_BEHAVIOR, GLFW_RELEASE_BEHAVIOR_FLUSH);

	//!				Window's context version

	//!					Window's context version major
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);

	//!					Window's context version minor
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	//!				OpenGL forward compatability
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

	//!				OpenGL core profile 
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//!				V-Sync off
	glfwSwapInterval(0);

	//!			Create window
	GLFWwindow* window = glfwCreateWindow(INITIALIZATION_GLFW_WINDOW_SIZE_X, INITIALIZATION_GLFW_WINDOW_SIZE_Y,
		"WeeRun", NULL, NULL);
	if (!window) {
		glfwTerminate();
#ifdef _DEBUG
		return glfwGetError(NULL);
#else
		return EXCEPTIONS_GLFW_INITIALIZATION_GLFWCREATEWINDOW;
#endif
	}
	//!			Set context
	glfwMakeContextCurrent(window);

	//!		OpenGL
	//!			Base
	if (!gladLoadGL()) {
		glfwDestroyWindow(window);
		glfwTerminate();
#ifdef _DEBUG
		return glGetError();
#else
		return EXCEPTIONS_OPENGL_INITIALIZATION_GLADLOADGL;
#endif
	}

	//!			Color buffer
	glClearColor(INITIALIZATION_OPENGL_BUFFERS_COLOR_CLEAR_NORMALIZED_RED,INITIALIZATION_OPENGL_BUFFERS_COLOR_CLEAR_NORMALIZED_GREEN,
		INITIALIZATION_OPENGL_BUFFERS_COLOR_CLEAR_NORMALIZED_BLUE,INITIALIZATION_OPENGL_BUFFERS_COLOR_CLEAR_NORMALIZED_ALFA);

	//!	Main loop
	while (!glfwWindowShouldClose(window)) {

		//!	OpenGL
		//!		Clear buffers
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);


		//!	WeeRun
		//TODO: Add Update methods 
		//TODO: Add Rendering methods 

		//! GLFW
		//!		Swap buffers
		glfwSwapBuffers(window);
#ifdef _DEBUG
		glfwWaitEvents();
#else
		glfwPollEvents();
#endif
	}

	glfwTerminate();
	return EXIT_SUCCESS;
}