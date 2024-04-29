#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

using namespace std;

// we use this shader to upload the cordinates of the shape in our pipeline
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main(\n"
"{\n"
"gl_position = vec4(aPos.x, aPos.y, aPos.z, 1.0); \n"
"}\0";

// we use it to generate the color of our color
const char* fragmenShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"FragColor = vec4(0.5, 0.0, 1.0);\n"
"}\n\0";

int main()
{	
	// Intializing GLFW
	glfwInit();

	// Specifiying which version we are using 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	// Declare vertices for our shape
	GLfloat vertices[] = {
		-0.5f, -0.5 * float(sqrt(3)) / 3, 0.0f,
		-0.5f, -0.5 * float(sqrt(3)) / 3, 0.0f,
		-0.5f, -0.5 * float(sqrt(3)) * 2 / 3, 0.0f,
	};

	// defining which shape are you going to use (Triangle for now)
	GLunit indices[] = {
		0, 3, 5,
		3, 2, 4,
		5, 4, 1,
	};

	// creating a window
	GLFWwinndow* window = glfwCreateWindow(800, 800, "Triangle", NULL, NULL);

	// error handling
	if (window == NULL)
	{
		cout << "Window failed" << endl;
		glfwTerminate();
		return -1;
	}

	// Introducing to the current context
	glfwMakeContextCurrent(window);

	// load glad
	gladLoadGl();

	// specify the view port in the window
	glViewport(0, 0, 900, 900);


	// call vertex shader
	GLunit vertextShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);

	// Compile vertex shader into GLSL
	glCompileShader(vertexShader);

	// call fragment shader
	GLunit fragmenShader = glCreateShader(GL_FRAGMENT_SHADER);
	glFragmentSource(fragmentShader, 1, &fragmenShaderSource, NULL);

	// compiling fragment shader into GLSL
	glCompileShader(fragmentShader);


	// attach shaders to shader program
	GLunit shaderProgram = glCreateProgram();
	glAttachShader(shadeProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);


	// deleting shader 
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	// creating VAO(Vertext Array Object) and VBO(vertex Buffer Object) references
	// declaration
	GLunit VAO, VBO;

	glGenVertextArrays(1 & VAO);
	glGenBuffer(1, &VBO);

	// Make the VBO the Current context
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	// Introduce the vertices into VBO
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), GL_STATIC_DRAW);

	// Tell OpenGL how to read VBO
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertextAtrribArray(0);

	// Bind the Buffer
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertextArray(0);

	// Define bgColor
	glClearColor(0.5f, 0.13f, 0.17f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);

	// main while loop
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.5f, 0.13f, 0.17f, 1.0f);
		// clean to buffer and assign new color
		glClear(GL_COLOR_BUFFER_BIT);

		//Tell openGl the shader program we use
		glUseProgram(ShaderProgram);

		// Bind VAO so OpenGL knows it
		glBindvertexArray(VAO);

		// Drawing a triangle
		glDrawArrays(GL_TRIANGLE, 0, 3);
		glDrawElements(GL_TRIANGLE, 9, GL_UNSIGNED_INTM 0);


		// Swap the back buffer with front buffer
		glfwSwapBuffer(window);
		glfwPollEvents();

	}

	// delete all the objects
	glDeleteVertexArray(1, &VAO);
	glDeleteBuffer(1, &VBO);
	glDeleteProgram(shaderProgram);
	glfwDestroyWindow(window);



	return 0;
}
