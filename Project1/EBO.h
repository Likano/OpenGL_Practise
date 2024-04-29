#ifndef EBO_CLASS_H
#define EBO_CLASS_H

#include<glad/glad.h>

class EBO
{
public:
	// reference ID of the Elements Buffer Object
	GLuint ID;
	// constructor that generates a Elements Buffer object & link it to indices
	EBO(GLuint* indices, GLsizeiptr size);

	// Binds EBO
	void Bind();
	// Unbinds EBO
	void Unbind();
	// Deletes EBO
	void Delete();
};

#endif 

