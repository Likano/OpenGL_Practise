#include"shaderClass.h"


// Reads a text file and outputs a string with every thing in the file
std::string get_file_contents(const char* filename)
{
	std::ifstream in(filename, std::ios::binary);
	if (in)
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
	throw(errno);
}

// constructor that build the Shader program from 2 different shaders
Shader::Shader(const char* vertexFile, const char* fragmentFile)
{
	// read VertexFile and fragmentFile and store the strings
	std::string vertexCode = get_file_contents(vertexFile);
	std::string fragmentCode = get_file_contents(fragmentFile);

	// Convert the shader source string into character array
	const char* vertexSource = vertexCode.c_str();
	const char* fragmentSource = fragmentCode.c_str();


	// Create Vertex shader object and get its reference
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	
	//Attach Vertex Shader source to the Vertex Shader object 
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	
	// Compile vertex shader into machine code
	glCompileShader(vertexShader);

	// Create fragment shader object and get its reference
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);

	// Compile source code into machine code for GPU
	glCompileShader(fragmentShader);

	// Attach shaders to shader program inorder to use them
	ID = glCreateProgram();
	
	// attach vertex & fragment shader to shader program
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	glLinkProgram(ID);

	// Delete the now useless Vertex and Fragment shader objects
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}


void Shader:: Activate()
{
	// Tell openGL which Shader program we use
	glUseProgram(ID);
}

void Shader::Delete()
{
	// Tell openGL which Shader program we delete
	glDeleteProgram(ID);
}