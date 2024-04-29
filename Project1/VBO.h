#ifndef VBO_CLASS_H
#define VBO_CLASS_H

#include<glad/glad.h>

class VBO
{
	public:
		// reference ID of the Vertex Buffer Object
		GLuint ID;
		// constructor that generates a Vertex Buffer object & link it to vertices
		VBO(GLfloat* vertices, GLsizeiptr size);

		// Binds the VBO
		void Bind();
		// Unbinds the VBO
		void Unbind();
		// Deletes the VBO
		void Delete();
};

#endif 

