#include"VAO.h"

// constructor that generates a Vertex Array Object (VAO) ID
VAO::VAO()
{
	// Generate the VAO and VBO with only 1 object
	glGenVertexArrays(1, &ID); 
}

// Links a VBO to the VAO using a certain layout
void VAO::LinkAttrib(VBO VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset)
{ 
	VBO.Bind();

	glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
	glEnableVertexAttribArray(layout);
	VBO.Unbind();
	
}

// Binds VAO
void VAO::Bind()
{
	// Make the VAO the current vertex array object by binding it
	glBindVertexArray(ID);
}

// Unbinds VAO
void VAO::Unbind()
{
	glBindVertexArray(0);
}

// Deletes VAO
void VAO::Delete()
{
	glDeleteVertexArrays(1, &ID);
}
