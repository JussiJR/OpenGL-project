/**
*  _____                                      _____
* ( ___ )                                    ( ___ )
*  |   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|   |
*  |   | #################################### |   |
*  |   | ##███╗###███╗#█████╗#██╗███╗###██╗## |   |
*  |   | ##████╗#████║██╔══██╗██║████╗##██║## |   |
*  |   | ##██╔████╔██║███████║██║██╔██╗#██║## |   |
*  |   | ##██║╚██╔╝██║██╔══██║██║██║╚██╗██║## |   |
*  |   | ##██║#╚═╝#██║██║##██║██║██║#╚████║## |   |
*  |   | ##╚═╝#####╚═╝╚═╝##╚═╝╚═╝╚═╝##╚═══╝## |   |
*  |   | #################################### |   |
*  |___|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|___|
* (_____)                                    (_____)
* 
*  _____
* /  ___|                                                  _
* \ `--.  _   _  _ __ ___   _ __ ___    __ _  _ __  _   _ (_)
*  `--. \| | | || '_ ` _ \ | '_ ` _ \  / _` || '__|| | | |
* /\__/ /| |_| || | | | | || | | | | || (_| || |   | |_| | _
* \____/  \__,_||_| |_| |_||_| |_| |_| \__,_||_|    \__, |(_)
*                                                    __/ |
*                                                   |___/
* 
* 
* 
* 
* 
* 
* ___  ___       _    _                 _         
* |  \/  |      | |  | |               | |      _ 
* | .  . |  ___ | |_ | |__    ___    __| | ___ (_)
* | |\/| | / _ \| __|| '_ \  / _ \  / _` |/ __|   
* | |  | ||  __/| |_ | | | || (_) || (_| |\__ \ _ 
* \_|  |_/ \___| \__||_| |_| \___/  \__,_||___/(_)
* 
* 
* 
* 
* 
* 
* 
* 
*  _   __                                   _
* | | / /                                  (_)                             _
* | |/ /  _ __    ___  __      __ _ __      _  ___  ___  _   _   ___  ___ (_)
* |    \ | '_ \  / _ \ \ \ /\ / /| '_ \    | |/ __|/ __|| | | | / _ \/ __|
* | |\  \| | | || (_) | \ V  V / | | | |   | |\__ \\__ \| |_| ||  __/\__ \ _
* \_| \_/|_| |_| \___/   \_/\_/  |_| |_|   |_||___/|___/ \__,_| \___||___/(_)
* 
* 
* 
* 
* 
* 
* 
* 
* 
* 
*  _    _        _           _  _                                         _
* | |  | |      | |         (_)| |                                       | | _
* | |  | |  ___ | |__   ___  _ | |_   ___  ___      _   _  ___   ___   __| |(_)
* | |/\| | / _ \| '_ \ / __|| || __| / _ \/ __|    | | | |/ __| / _ \ / _` |
* \  /\  /|  __/| |_) |\__ \| || |_ |  __/\__ \    | |_| |\__ \|  __/| (_| | _
*  \/  \/  \___||_.__/ |___/|_| \__| \___||___/     \__,_||___/ \___| \__,_|(_)
* 
* 
*	- https://www.asciiart.eu/text-to-ascii-art - To create ASCII art for header and documentation files
*	- https://www.glfw.org/docs/latest/ - GLFW Documentation... Well what you expect? Donuts?
*	- https://registry.khronos.org/OpenGL/index_gl.php - OpenGL Documentation... Deja wu time?
* 
* 
* 
* 
* 
* 
*/
#pragma once
#ifndef __main_h_
#define __main_h_


//!	Includes

//!		iostream
//!			Header files
#include <iostream>

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
#define INITIALIZATION_OPENGL_BUFFERS_COLOR_CLEAR_NORMALIZED_ALFA 0.937

//!		Exceptions
//!			GLFW
//!				Initializations
#define EXCEPTIONS_GLFW_INITIALIZATION_GLFWINIT 0x100F
#define EXCEPTIONS_GLFW_INITIALIZATION_GLFWCREATEWINDOW 0x101F

//!			OpenGL
//!				Initialization
#define EXCEPTIONS_OPENGL_INITIALIZATION_GLADLOADGL 0x200F

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
#endif