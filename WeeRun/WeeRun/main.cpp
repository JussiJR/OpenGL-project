#include "main.h"

//!	Methods
//!		Main
int main(int argc, char** argv){
	int errorc = 0;
	//!	Initialize GLFW
	if (InitializeGLFW()) return CustomGLFW_Initialization_exception;// specifies exception
	
	//!	Initialize GLFWwindow	
	GLFWwindow* window = InitializeWindow(&errorc); // window of the game
	if (errorc) return CustomGLFW_Window_Initialization_Exception;

	//!	Initialize OpenGL
	if (InitializeOpenGL(window)) return CustomOpenGL_Initialization_Exception;


	//! Initialize game manager
	GameManager manager = GameManager("chunk_data.json");
	if (manager.Initialized) {
		errorc = manager.Initialized;
		goto cleanUp;
	}

	//!	Main loop
	while (!glfwWindowShouldClose(window)) {

		//!	OpenGL
		//!		Clear buffers
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

		//!	WeeRun
		//!		Updating
		manager.Update(window,&errorc);
		if (errorc) glfwSetWindowShouldClose(window,1); // updated once every frame
		
		//!		Rendering
		manager.Render(&errorc, 5);
		if (errorc) glfwSetWindowShouldClose(window, 1); // draws once every frame

		//! GLFW
		//!		Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

cleanUp:
	glfwDestroyWindow(window);
	glfwTerminate();
	return errorc;
}

void Keyboard_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
	//FIXME: FIX THIS SHIT 
	if (GLFW_PRESS == action) {
		if (GLFW_KEY_ESCAPE == key) {
			glfwSetWindowShouldClose(window, GLFW_TRUE);
		}
	}

}

void CursorPosition_callback(GLFWwindow* window, double position_X, double position_Y)
{

}

inline int InitializeGLFW(void) {
	glfwInitHint(GLFW_JOYSTICK_HAT_BUTTONS, GLFW_FALSE);
	if (!glfwInit()) {
#ifdef _DEBUG
		
#endif
		return CustomGLFW_Exception;
	}
	return 0;
}
inline GLFWwindow* InitializeWindow(int* errorc) {

	//!	Window hints
#ifndef _DEBUG
	//!		Window's borders
	glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);

	//!		Window's always on top
	glfwWindowHint(GLFW_FLOATING, GLFW_TRUE);

	//!		Window's debuggability off
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_FALSE);

#else
	//!		Window's debuggability on
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);

#endif
	//!		Window's resizability
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	//!		Window's auto iconifying
	glfwWindowHint(GLFW_AUTO_ICONIFY, GLFW_TRUE);

	//!		Window's context release behavior
	glfwWindowHint(GLFW_CONTEXT_RELEASE_BEHAVIOR, GLFW_RELEASE_BEHAVIOR_FLUSH);

	//!		Window's context version

	//!			Window's context version major
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);

	//!			Window's context version minor
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	//!		OpenGL forward compatability
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

	//!		OpenGL core profile 
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//!		V-Sync off
	glfwSwapInterval(0);

	//!	Create window
	GLFWwindow* window = glfwCreateWindow(800, 500,"WeeRun", NULL, NULL);
	if (!window) {
		glfwTerminate();
#ifdef _DEBUG
#endif
		*errorc = CustomGLFW_Window_Exception;
		return nullptr;
	}

	//!	Set context
	glfwMakeContextCurrent(window);
	
	return window;
}

inline int InitializeOpenGL(GLFWwindow* window) {
	if (!gladLoadGL()) {
		glfwDestroyWindow(window);
		glfwTerminate();
#ifdef _DEBUG

#endif
		return CustomOpenGL_Exception;
	}
	//!			Color buffer
	glClearColor(0.675f, 0.522f, 1.0f, 0.6937f);
	glEnable(GL_DEPTH_TEST);
	return EXIT_SUCCESS;
}