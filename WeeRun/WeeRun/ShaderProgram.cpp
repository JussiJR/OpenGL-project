#include "ShaderProgram.h"
inline string readFile(const char* path);
ShaderProgram::ShaderProgram()
{
	ID = 0;
}
ShaderProgram::ShaderProgram(const char* vertexPath, const char* fragmentPath, int* errorc)
{

	std::string VertexCode = readFile(vertexPath);
	std::string fragCode = readFile(fragmentPath);

	const char* c_vertexCode = VertexCode.c_str();
	const char* c_fragmentCode = VertexCode.c_str();

	//!	Vertex shader
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &c_vertexCode, NULL);
	glCompileShader(vertexShader);


	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, errorc);
	if (*errorc == GL_FALSE) {
		*errorc = Shader_Vertex_Compile_Exception;
		return;
	}

	//!	Fragmen shader
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &c_fragmentCode, NULL);
	glCompileShader(fragmentShader);

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, errorc);
	if (*errorc == GL_FALSE) {
		*errorc = Shader_Fragment_Compile_Exception;
		return;
	}


	//!	Shader program
	ID = glCreateProgram();
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	glLinkProgram(ID);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

}

void ShaderProgram::Activate()
{
	glUseProgram(ID);
}

void ShaderProgram::Delete()
{
	glDeleteProgram(ID);
}
GLint ShaderProgram::getUniform(const char* name) const
{
	if (uniformCache.find(name) != uniformCache.end()) return uniformCache[name];
	GLint location = glGetUniformLocation(ID, name);
	if (location != -1) uniformCache[name] = location;
	return location;
}

inline string readFile(const char* path) {
	ifstream in(path, ios::binary);
	if (!in) throw(errno);

	//! Read contents
	string contents;
	in.seekg(0, ios::end);
	contents.resize(in.tellg());
	in.seekg(0, ios::beg);
	in.read(&contents[0], contents.size());
	in.close();

	return (contents);

}