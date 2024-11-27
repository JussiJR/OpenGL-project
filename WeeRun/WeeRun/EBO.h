




#ifndef EBO_CLASS_H
#define EBO_CLASS_H


//!Includes
//!		OpenGL
#include<glad/glad.h>

//!		Vector
#include<vector>


//!	Defines


//!	Classes
//!		Element buffer object

/// <summary>
/// EBO or Element buffer object is for rendering it gives info how the objects are drawn
/// </summary>
class EBO
{
public:

	/// <summary>
	/// ID for Elemeent buffer object
	/// </summary>
	GLuint ID;
	
	/// <summary>
	/// Empty contructor
	/// </summary>
	EBO();
	
	/// <summary>
	/// Actual constructor
	/// </summary>
	/// <param name="indices"> Indices</param>
	EBO(std::vector<GLubyte>& indices);

	/// <summary>
	/// Bind method for EBO
	/// </summary>
	void Bind();
	
	/// <summary>
	/// Unbind method for EBO
	/// </summary>
	void Unbind();
	
	/// <summary>
	/// Delete method for EBO
	/// </summary>
	void Delete();
};
#endif