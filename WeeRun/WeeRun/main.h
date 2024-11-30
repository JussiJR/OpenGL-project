/*
*	  _____                                      _____
*	 ( ___ )                                    ( ___ )
*	  |   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|   |
*	  |   | #################################### |   |
*	  |   | ##███╗###███╗#█████╗#██╗███╗###██╗## |   |
*	  |   | ##████╗#████║██╔══██╗██║████╗##██║## |   |
*	  |   | ##██╔████╔██║███████║██║██╔██╗#██║## |   |
*	  |   | ##██║╚██╔╝██║██╔══██║██║██║╚██╗██║## |   |
*	  |   | ##██║#╚═╝#██║██║##██║██║██║#╚████║## |   |
*	  |   | ##╚═╝#####╚═╝╚═╝##╚═╝╚═╝╚═╝##╚═══╝## |   |
*	  |   | #################################### |   |
*	  |___|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|___|
*	 (_____)                                    (_____)
*	 
*	  _____
*	 /  ___|                                                  _
*	 \ `--.  _   _  _ __ ___   _ __ ___    __ _  _ __  _   _ (_)
*	  `--. \| | | || '_ ` _ \ | '_ ` _ \  / _` || '__|| | | |
*	 /\__/ /| |_| || | | | | || | | | | || (_| || |   | |_| | _
*	 \____/  \__,_||_| |_| |_||_| |_| |_| \__,_||_|    \__, |(_)
*	                                                    __/ |
*	                                                   |___/
*	 
*	 
*		
*	 
*	 
*	 
*	 ___  ___       _    _                 _         
*	 |  \/  |      | |  | |               | |      _ 
*	 | .  . |  ___ | |_ | |__    ___    __| | ___ (_)
*	 | |\/| | / _ \| __|| '_ \  / _ \  / _` |/ __|   
*	 | |  | ||  __/| |_ | | | || (_) || (_| |\__ \ _ 
*	 \_|  |_/ \___| \__||_| |_| \___/  \__,_||___/(_)
*	 
*		<summary>
*		Main entry point for main thread
*		</summary>
*		<param name="argc"> Argument count </param>
*		<param name="argv"> Argument vector </param>
*		<returns> 0 if all go according to plan otherwise error code as a Hexadecimal.</returns>
*		int main(int argc, char** argv);
*
*	  _   __                                   _
*	 | | / /                                  (_)                             _
*	 | |/ /  _ __    ___  __      __ _ __      _  ___  ___  _   _   ___  ___ (_)
*	 |    \ | '_ \  / _ \ \ \ /\ / /| '_ \    | |/ __|/ __|| | | | / _ \/ __|
*	 | |\  \| | | || (_) | \ V  V / | | | |   | |\__ \\__ \| |_| ||  __/\__ \ _
*	 \_| \_/|_| |_| \___/   \_/\_/  |_| |_|   |_||___/|___/ \__,_| \___||___/(_)
*	 
*	 
*
*	 
*	  _    _        _           _  _                                         _
*	 | |  | |      | |         (_)| |                                       | | _
*	 | |  | |  ___ | |__   ___  _ | |_   ___  ___      _   _  ___   ___   __| |(_)
*	 | |/\| | / _ \| '_ \ / __|| || __| / _ \/ __|    | | | |/ __| / _ \ / _` |
*	 \  /\  /|  __/| |_) |\__ \| || |_ |  __/\__ \    | |_| |\__ \|  __/| (_| | _
*	  \/  \/  \___||_.__/ |___/|_| \__| \___||___/     \__,_||___/ \___| \__,_|(_)
*	 
*	 
*		- https://www.glfw.org/docs/latest/ - GLFW Documentation.
*		- https://registry.khronos.org/OpenGL/index_gl.php - OpenGL Documentation.
*		- https://web.engr.oregonstate.edu/~mjb/cs491/Handouts/GLM.1pp.pdf - GLM Documentation.
* 
* 
*/
#pragma once
#ifndef __main_h_
#define __main_h_


//!	Includes

//!		stdio
//!			Header files
#include <stdio.h>

//!		Game manager
#ifndef __gameamanager_h_
//!			Header files
#include "gamemanager.h"
#endif
//!		GLFW 
#if !defined(_glfw3_h_)

//!			Definitions
#define GLFW_INCLUDE_NONE

//!			Header files
#include <GLFW/glfw3.h>
#endif

//!		OpenGL Loader
#if !defined(__glad_h_)

//!			Header files
#include <glad/glad.h>
#endif

//! Definitions
//!		Initialization
//!			GLFW
//!				Window
//!					Size
#define INITIALIZATION_GLFW_WINDOW_SIZE_X 800
#define INITIALIZATION_GLFW_WINDOW_SIZE_Y 540
#define INITIALIZATION_GLFW_WINDOW_SIZE_BUFFER_SIZE INITIALIZATION_GLFW_WINDOW_SIZE_X * INITIALIZATION_GLFW_WINDOW_SIZE_Y

//!			OpenGL
//!				Buffers
//!					Color
//!						Clear
#define INITIALIZATION_OPENGL_BUFFERS_COLOR_CLEAR_NORMALIZED_RED 0.675f
#define INITIALIZATION_OPENGL_BUFFERS_COLOR_CLEAR_NORMALIZED_GREEN 0.522f
#define INITIALIZATION_OPENGL_BUFFERS_COLOR_CLEAR_NORMALIZED_BLUE 1.0f
#define INITIALIZATION_OPENGL_BUFFERS_COLOR_CLEAR_NORMALIZED_ALFA 0.6937f

//!		Exceptions
//!			GLFW
//!				Initializations
#define EXCEPTIONS_GLFW_INITIALIZATION_GLFWINIT 0x100F
#define EXCEPTIONS_GLFW_INITIALIZATION_GLFWCREATEWINDOW 0x101F

//!			OpenGL
//!				Initialization
#define EXCEPTIONS_OPENGL_INITIALIZATION_GLADLOADGL 0x20F

//!		Misc
//!			Exit codes
#if !defined(EXIT_SUCCESS)
#define EXIT_SUCCESS 0
#endif

#if defined(_DEBUG)
//!		Debug
//!			Logging
#define DEBUG_LOGGING_ERROR(message)  fprintf(stderr ,"LOG Error: " message "\n" )		// Log error messages
#define DEBUG_LOGGING_WARNING(message)  fprintf(stderr,"LOG Warning: " message "\n")	// Log warning messages
#define DEBUG_LOGGING_LOG(message)  fprintf(stderr, "LOG Log: " message "\n")			// Log error messages
#endif

//! Methods
//!		Main entrypoint

/// <summary>
/// Main entry point for main thread
/// </summary>
/// <param name="argc"> Argument count </param>
/// <param name="argv"> Argument vector </param>
/// <returns> 0 if all go according to plan otherwise error code as a Hexadecimal.</returns>
int main(int argc, char** argv);


//!		Call backs
//!			All
//!				Keyboard

/// <summary>
/// Key callback for GLFW window's keyboard input
/// </summary>
/// <param name="window">Target window</param>
/// <param name="key">integer representing pressed input</param>
/// <param name="scancode">scancode for button</param>
/// <param name="action">int representing action</param>
/// <param name="mods">integer representing mods</param>
void Keyboard_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

//!				Mouse
//!					Cursor position

/// <summary>
/// Cursor position callback for GLFW window
/// </summary>
/// <param name="window">target window</param>
/// <param name="position_X">position of the cursor in x axel</param>
/// <param name="position_Y">position of the cursor in y axel</param>
void CursorPosition_callback(GLFWwindow* window, double position_X, double position_Y);
#endif