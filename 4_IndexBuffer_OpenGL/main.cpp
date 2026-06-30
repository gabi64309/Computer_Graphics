/*
Language: C++

Author: gabi64309

Last update [mm/dd/yyyy]: 06/30/2026

Description:
Demonstrates indexed rendering in Modern OpenGL using an Element Buffer
Object (EBO). The program initializes an OpenGL 3.3 Core context with
GLFW and GLAD, uploads vertex and index data to GPU memory, configures
a Vertex Array Object (VAO), compiles basic shaders, and renders the
geometry using glDrawElements(). The project illustrates how index
buffers reduce duplicated vertex data by allowing multiple triangles to
share the same vertices, improving memory efficiency and matching the
standard rendering approach used in modern graphics APIs.
*/

#include <iostream>
#define GLFW_INCLUDE_NONE // No matter the common order: glad.h first just right before glfw3.h
#include <glad/glad.h> // Extension loader library. 
#include <GLFW/glfw3.h> // Only in the source files.

#include <cmath>


void errorCallback(int error, const char* description) {
	std::cerr << description << '\n';
}

// Defaults for vertex and fragment shader
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"	FragColor = vec4(0.99f, 1.0f, 1.0f, 1.0f);\n"
"}\n\0";

int main() {

	glfwSetErrorCallback(errorCallback);

	// Fail-fast.
	if (!glfwInit()) {
		std::cout << "Failed to initialize GLFW" << std::endl;
		return -1;
	}
	/*
	Instead, you can try :
		if (glfwInit() == GLFW_FALSE)
		{
			return EXIT_FAILURE;
		}
	*/

	GLFWmonitor* monitor = glfwGetPrimaryMonitor();
	const GLFWvidmode* mode = glfwGetVideoMode(monitor);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // COMP_PROFILE (COMP = COMPATIBILITY) have outdated and modern functions. CORE only have modern functions.
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // For Mac OS X users.

	GLfloat vertices[] =
	{
		-0.65f, -0.85f * float(sqrt(3)) / 3, 0.0f,
		0.53f, -0.30f * float(sqrt(3)) / 3, 0.0f,
		0.0f, 0.2f * float(sqrt(3)) * 2 / 3, 0.0f,
		0.0f, 0.0f * float(sqrt(3)) / 3, 0.0f,
		0.2f, 0.0f * float(sqrt(3)) / 3, 0.0f,
		0.0f, -0.3f * float(sqrt(3)) / 3, 0.0f
	};

	GLuint indices[] =
	{
		0, 3, 2,
		0, 1, 4,
		4, 2, 1,
		3, 4, 2,
		0, 3, 5
	};

	GLFWwindow* window = glfwCreateWindow(
		mode->width,
		mode->height,
		"OpenGL",
		monitor,
		NULL
	); // Args: width, heigh, name_of_window, primary_monitor...

	if (!window) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGL()) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	glViewport(0, 0, mode->width, mode->height);

	// A.K.A values
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	GLuint shaderProgram = glCreateProgram();

	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);

	glLinkProgram(shaderProgram);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	// Reference integer
	// VBO is an array of references
	GLuint VAO, VBO, EBO;

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO); // Create vertex buffer object
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	// Store vertices in the VBO
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	/*
	STREAM, STATIC and DYNAMIC.
	STREAM means that the vertices will be modified once and used a few times.
	STATIC means that the vertices will be modifiende once and used many many times.
	DYNAMIC means that the vertices eill be modified multiple times and used many many times.

	DRAW, READ and COPY
	DRAW means that the vertices will be modified and be used to draw an image on the screen.
	*/

	// Now, lets make OpenGL know where to find the stored vertices above. Use another object: Vertex array object.
	// This stores pointers to one or more VBOs, and tells OpenGL how to interpret them. Put always the VAO before the VBO.

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	glClearColor(0.2f, 0.6f, 0.51f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);

	while (!glfwWindowShouldClose(window)) {

		glClearColor(0.2f, 0.6f, 0.51f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 15, GL_UNSIGNED_INT, 0);
		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glDeleteProgram(shaderProgram);

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}