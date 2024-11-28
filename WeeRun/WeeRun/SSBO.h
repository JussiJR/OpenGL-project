/**
*  _____                                                                                                                 _____
* ( ___ )                                                                                                               ( ___ )
*  |   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|   |
*  |   | ############################################################################################################### |   |
*  |   | ##███████╗██╗##██╗#█████╗#██████╗#███████╗██████╗#███████╗████████╗#██████╗#██████╗##█████╗##██████╗#███████╗## |   |
*  |   | ##██╔════╝██║##██║██╔══██╗██╔══██╗██╔════╝██╔══██╗██╔════╝╚══██╔══╝██╔═══██╗██╔══██╗██╔══██╗██╔════╝#██╔════╝## |   |
*  |   | ##███████╗███████║███████║██║##██║█████╗##██████╔╝███████╗###██║###██║###██║██████╔╝███████║██║##███╗█████╗#### |   |
*  |   | ##╚════██║██╔══██║██╔══██║██║##██║██╔══╝##██╔══██╗╚════██║###██║###██║###██║██╔══██╗██╔══██║██║###██║██╔══╝#### |   |
*  |   | ##███████║██║##██║██║##██║██████╔╝███████╗██║##██║███████║###██║###╚██████╔╝██║##██║██║##██║╚██████╔╝███████╗## |   |
*  |   | ##╚══════╝╚═╝##╚═╝╚═╝##╚═╝╚═════╝#╚══════╝╚═╝##╚═╝╚══════╝###╚═╝####╚═════╝#╚═╝##╚═╝╚═╝##╚═╝#╚═════╝#╚══════╝## |   |
*  |   | ############################################################################################################### |   |
*  |   | ##██████╗#██╗###██╗███████╗███████╗███████╗██████╗##██████╗#██████╗######██╗███████╗#██████╗████████╗########## |   |
*  |   | ##██╔══██╗██║###██║██╔════╝██╔════╝██╔════╝██╔══██╗██╔═══██╗██╔══██╗#####██║██╔════╝██╔════╝╚══██╔══╝########## |   |
*  |   | ##██████╔╝██║###██║█████╗##█████╗##█████╗##██████╔╝██║###██║██████╔╝#####██║█████╗##██║########██║############# |   |
*  |   | ##██╔══██╗██║###██║██╔══╝##██╔══╝##██╔══╝##██╔══██╗██║###██║██╔══██╗██###██║██╔══╝##██║########██║############# |   |
*  |   | ##██████╔╝╚██████╔╝██║#####██║#####███████╗██║##██║╚██████╔╝██████╔╝╚█████╔╝███████╗╚██████╗###██║############# |   |
*  |   | ##╚═════╝##╚═════╝#╚═╝#####╚═╝#####╚══════╝╚═╝##╚═╝#╚═════╝#╚═════╝##╚════╝#╚══════╝#╚═════╝###╚═╝############# |   |
*  |   | ############################################################################################################### |   |
*  |___|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|___|
* (_____)                                                                                                               (_____)
*
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
*		this object is used for storing lot of stuff more than 16kb to be precise aka chunks XD
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
* 
* 
*	
*		<summary>
*		Empty contstructor
*		</summary>
*		SSBO();
*	
*		<summary>
*		Real constructor
*		</summary>
*		<param name="data"> Data to be init</param>
*		<param name="type"> Type of the memory space</param>
*		<param name="index"> Index where ssbo will be inserted in buffer</param>
*		SSBO(std::vector<void*> data, GLenum type, int index);
*		
*
*		<summary>
*		Update method for data inside of a SSBO
*		</summary>
*		<param name="size">Size of the are</param>
*		<param name="offset">Offset for the starting point</param>
*		<param name="data">data to be inserted</param>
*		void Update(GLintptr size, GLintptr offset, const void* data);
*
*
*		<summary>
*		Activation method
*		</summary>
*		void Activate();
*	
*	
*		<summary>
*		Disposing method or more precisely wrapper around opengl
*		</summary>
*		void Delete();
*
*	  _   __                                   _
*	 | | / /                                  (_)                             _
*	 | |/ /  _ __    ___  __      __ _ __      _  ___  ___  _   _   ___  ___ (_)
*	 |    \ | '_ \  / _ \ \ \ /\ / /| '_ \    | |/ __|/ __|| | | | / _ \/ __|
*	 | |\  \| | | || (_) | \ V  V / | | | |   | |\__ \\__ \| |_| ||  __/\__ \ _
*	 \_| \_/|_| |_| \___/   \_/\_/  |_| |_|   |_||___/|___/ \__,_| \___||___/(_)
*
*		No issues found yet
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
*		- https://www.khronos.org/opengl/wiki/Shader_Storage_Buffer_Object - More information about SSBOs
*		- https://community.khronos.org/t/multiple-ssbos-access/111107 - About optimizations
*		- https://www.reddit.com/r/opengl/comments/16zvg6t/multiple_ssbos_and_gldrawelements_with_same/ - MORE information about ssbos
* 
* 
*/

#pragma once
#ifndef __ssbo_h_
#define __ssbo_h_

//!		GLFW
#if !defined(__glfw3_h_)

//!			Definitions
	#if !defined(GLFW_INCLUDE_NONE)
	#define GLFW_INCLUDE_NONE
	#endif
//!			Header files
	#include <GLFW/glfw3.h>

#endif

//!		OpenGL
#include <glad/glad.h>

//!		stdint
#include <stdint.h>

//!		Vector
#include <vector>

//! Definitions


//!	Classes
//!		SSBO

/// <summary>
/// SSBO (Shader storage buffer object)
/// </summary>


template <typename T> class SSBO {
public:

	/// <summary>
	/// ID for SSBO or more precisely nint 
	/// </summary>
	GLuint ID;

	/// <summary>
	/// Empty contstructor
	/// </summary>
	SSBO();

	/// <summary>
	/// Real constructor
	/// </summary>
	/// <param name="data"> Data to be init</param>
	/// <param name="type"> Type of the memory space</param>
	/// <param name="index"> Index where ssbo will be inserted in buffer</param>
	SSBO(std::vector<T> data, GLenum type, int index);

	/// <summary>
	/// Update method for data inside of a SSBO
	/// </summary>
	/// <param name="size">Size of the are</param>
	/// <param name="offset">Offset for the starting point</param>
	/// <param name="data">data to be inserted</param>
	void Update(GLintptr size, GLintptr offset, const T data);

	/// <summary>
	/// Activation method
	/// </summary>
	void Activate();

	/// <summary>
	/// Disposing method or more precisely wrapper around opengl
	/// </summary>
	void Delete();
};
#endif