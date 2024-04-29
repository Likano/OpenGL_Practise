#ifndef SHADER_ClASS_H
#define SHADER_CLASS_H

#include<glad/glad.h>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<cerrno>
    
std::string get_file_contents(const char* filename);

class Shader {
	public:
		// reference ID of the shader program
		GLuint ID;

		// constructor that build the shader program
		Shader(const char* vertexFile, const char* fragmentFile);
	
		// Activates the Shader Program
		void Activate();
		// Deletes the shader program
		void Delete();
};

#endif