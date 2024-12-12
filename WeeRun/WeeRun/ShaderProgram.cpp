#include "ShaderProgram.h"
inline string readFile(std::string path);
ShaderProgram::ShaderProgram()
{
	ID = 0;
}
ShaderProgram::ShaderProgram(const char* vertexPath, const char* fragmentPath, int* errorc)
{
	GLchar buffer[512];
	int success;

	std::string VertexCode = readFile(vertexPath);
	std::string fragCode = readFile(fragmentPath);

	const char* c_vertexCode = VertexCode.c_str();
	const char* c_fragmentCode = fragCode.c_str();

	//!	Vertex shader
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &c_vertexCode, NULL);
	glCompileShader(vertexShader);
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	std::cout << "VertexShader: \n" << std::endl;
	glGetShaderInfoLog(vertexShader, 512, NULL, buffer);
	std::cout << buffer << std::endl;
	std::cout << VertexCode << endl;
	if (success == GL_FALSE) {
		*errorc = Shader_Vertex_Compile_Exception;
		return;
	}

	//!	Fragmen shader
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &c_fragmentCode, NULL);
	glCompileShader(fragmentShader);
	std::cout << "Fragment shader: \n" << std::endl;
	glGetShaderInfoLog(fragmentShader, 512, NULL, buffer);
	std::cout << buffer << std::endl;
	std::cout << fragCode << endl;
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (success == GL_FALSE) {
		*errorc = Shader_Fragment_Compile_Exception;
		return;
	}

	//!	Shader program
	ID = glCreateProgram();
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	glLinkProgram(ID);
	glGetProgramiv(ID, GL_LINK_STATUS, &success);
	if (!success) {
		char infoLog[512];
		glGetProgramInfoLog(ID, 512, NULL, infoLog);
		std::cerr << "Program Linking Error:\n" << infoLog << std::endl;
	}
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

inline string readFile(std::string path) {
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