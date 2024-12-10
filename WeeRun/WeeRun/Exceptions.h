#pragma once
#ifndef __exceptions_h_
#define __exceptions_h_

enum Exceptions_e {

	//!	No Exceptions
	
	/// <summary>
	/// Default state of no exception
	/// </summary>
	Exceptions_Null = 0,

	//!	Map based excepions

	/// <summary>
	/// Default exception of maps.
	/// Thrown: when there is no other suitable Exception
	/// </summary>
	Map_Exception = 0x100F,

	/// <summary>
	/// map not found exception
	/// Thrown: when map file is not found
	/// </summary>
	Map_MapNotFound_Exception = 0x101F,

	/// <summary>
	/// invalid map extension exception
	/// Thrown: when map file has invalid file extension
	/// </summary>
	Map_InvalidMapExtension_Exception = 0x102F,

	/// <summary>
	/// broken map exception
	/// Thrown: when map is broken and cannot be read properly
	/// </summary>
	Map_BrokenMap_Exception = 0x103F,

	//!	Map tree based excepions

	/// <summary>
	/// Default exception of map trees.
	/// Thrown: when there is no other suitable Exception
	/// </summary>
	MapTree_Exception = 0x200F,

	/// <summary>
	/// map tree invalid map exception
	/// Thrown: thrown when map tree does not meet the requirements
	/// </summary>
	MapTree_InvalidMap_Excecution = 0x201F,


	/// <summary>
	/// map tree link failure exception
	/// Thrown:when map tree has linking problems.
	/// </summary>
	MapTree_LinkFailure_Exception = 0x202F,

	//!	GLFW custom exceptions

	/// <summary>
	/// Default exception of CustomGLFW.
	/// Thrown: when there is no other suitable Exception
	/// </summary>
	CustomGLFW_Exception = 0x300F,

	/// <summary>
	/// CustomGLFW initialization exception
	/// Thrown: when program is unable to initialize GLFW api.
	/// </summary>
	CustomGLFW_Initialization_exception = 0x301F,

	/// <summary>
	/// Default exception of GLFW window.
	/// Thrown: when there is no other suitable Exception
	/// </summary>
	CustomGLFW_Window_Exception = 0x301F,

	/// <summary>
	///	CustomGLFW window exception 
	/// Thrown: when program window is unable to initialize window for some reason.
	/// </summary>
	CustomGLFW_Window_Initialization_Exception = 0x302F,

	//!	Shader exceptions

	/// <summary>
	/// Default exception of Shaders.
	/// Thrown: when there is no other suitable Exception
	/// </summary>
	Shader_Exception = 0x400F,

	/// <summary>
	/// Default exception of Vertex shader.
	/// Thrown: when there is no other suitable Exception
	/// </summary>
	Shader_Vertex_Exception = 0x401F,

	/// <summary>
	/// Vertex shader not found.
	/// Thrown: when program is not able to find vertex shader.
	/// </summary>
	Shader_Vertex_NotFound_Exception = 0x402F,

	/// <summary>
	/// Vertex shader compile exception
	/// Thrown: When program is not able to compile vertex shader
	/// </summary>
Shader_Vertex_Compile_Exception = 0x403F,

/// <summary>
/// Default exception of Fragment shader.
/// Thrown: when there is no other suitable Exception 
/// </summary>
Shader_Fragment_Exception = 0x404F,

/// <summary>
/// Fragment shader not found exception
/// Thrown: when fragment shader file is not found
/// </summary>
Shader_Fragment_NotFound_Exception = 0x405F,

/// <summary>
/// Default exception of Shader program.
/// Thrown: when there is no other suitable Exception 
/// </summary>
Shader_ShaderProgram_Exception = 0x407F,

/// <summary>
/// Default exception of shader uniforms.
/// Thrown: when there is no other suitable Exception
/// </summary>
Shader_ShaderProgram_ShaderUniform_Exception = 0x408F,

/// <summary>
/// Shader uniform not found exception	
/// Thrown: when Shader uniform not found
/// </summary>
Shader_ShaderProgram_ShaderUniform_NotFound_Exception = 0x409F,

/// <summary>
/// Shader uniform invalid data exception	
/// Thrown: when shader uniform's data does not equal to expected 
/// </summary>
Shader_ShaderProgram_ShaderUniform_InvalidData_Exception = 0x410F,

/// <summary>
/// shader uniform invalid operation exception	
/// Thrown: when Operation is invalid in some other way than data is not maching
/// </summary>
Shader_ShaderProgram_ShaderUniform_InvalidOperation_Exception = 0x411F,

/// <summary>
/// Shader program validate exception.
/// Thrown: when program is not able to validate shader program.
/// </summary>
Shader_ShaderProgram_Validate_Exception = 0x412F,

/// <summary>
/// Default exception of textures.
/// Thrown: when there is no other suitable Exception
/// </summary>
Texture_Exception = 0x500F,

/// <summary>
/// Invalid texture exception 	
/// Thrown: when texture is invalid.
/// </summary>
Texture_InvalidTexture_Exception = 0x501F,

/// <summary>
/// Invalid texture texture not found exception
/// Thrown: when texture file is not found.
/// </summary>
Texture_InvalidTexture_TextureNotFound_Exception = 0x502F,

/// <summary>
/// Texture is not valid exception	
/// Thrown: when texture is not valid.
/// </summary>
Texture_InvalidTexture_TextureIsNotValid_Exception = 0x503F,

/// <summary>
/// Invalid texture openGL side exception	
/// Thrown: thrown when program is not able to resolve openGL sided problem
/// </summary>
Texture_InvalidTexture_OpenGLSide_Exception = 0x504F,

/// <summary>
/// Default exception of dynamic memory.
/// Thrown: when there is no other suitable Exception
/// </summary>
DynamicMemory_Exception = 0x600F,

/// <summary>
/// dynamic memory allocation exception
/// thrown when program is not able to allocate dynamic memory
/// </summary>
DynamicMemory_Allocation_Exception = 0x601F,

/// <summary>
/// default exception of CustomOpenGL
/// Thrown: when no other exception satisfies requirements.
/// </summary>
CustomOpenGL_Exception = 0x700F,

/// <summary>
/// Custom openGL initialization exception
/// Thrown:
/// </summary>
CustomOpenGL_Initialization_Exception = 0x701F
}; 
#endif	
