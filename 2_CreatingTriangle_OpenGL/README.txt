# OpenGL – Rendering a Triangle

A minimal Modern OpenGL application written in C++ that demonstrates how to render a single triangle using the programmable graphics pipeline.

This project serves as a beginner-friendly introduction to Modern OpenGL (Core Profile 3.3), replacing the deprecated fixed-function pipeline with shaders, buffer objects, and vertex array objects.

---

# Screenshot

```
          /\
         /  \
        /    \
       /______\
```

A cyan triangle rendered over a dark background.

---

# Features

- Modern OpenGL 3.3 Core Profile
- GLFW window and OpenGL context creation
- GLAD OpenGL function loading
- Vertex Shader
- Fragment Shader
- Shader Program creation
- Vertex Buffer Object (VBO)
- Vertex Array Object (VAO)
- Rendering using `GL_TRIANGLES`
- Fullscreen rendering
- Basic fail-fast error handling

---

# Technologies

- C++
- OpenGL 3.3
- GLFW
- GLAD
- GLSL

---

# Project Structure

```
.
├── main.cpp
├── glad/
├── GLFW/
└── README.md
```

---

# Requirements

- C++17 or newer
- OpenGL 3.3 compatible GPU
- GLFW
- GLAD

---

# Building

Windows (MinGW example)

```bash
g++ main.cpp -o Triangle ^
-Iinclude ^
-Llib ^
-lglfw3 -lopengl32
```

Linux

```bash
g++ main.cpp -o Triangle \
-lglfw \
-lGL \
-ldl \
-pthread
```

> The compilation command depends on your compiler and library installation.

---

# How It Works

The application performs the following steps:

1. Initializes GLFW.
2. Creates an OpenGL Core Profile context.
3. Loads OpenGL function pointers using GLAD.
4. Compiles the Vertex Shader.
5. Compiles the Fragment Shader.
6. Links both shaders into a Shader Program.
7. Creates a Vertex Buffer Object (VBO).
8. Uploads the triangle vertices to GPU memory.
9. Creates and configures a Vertex Array Object (VAO).
10. Clears the framebuffer.
11. Draws one triangle.
12. Repeats until the window is closed.

---

# Graphics Pipeline

```
Triangle Vertices
        │
        ▼
 Vertex Shader
        │
        ▼
 Primitive Assembly
 (GL_TRIANGLES)
        │
        ▼
 Rasterization
        │
        ▼
 Fragment Shader
        │
        ▼
   Framebuffer
        │
        ▼
     Display
```

---

# Triangle Vertex Data

The triangle is composed of three vertices:

```cpp
GLfloat vertices[] =
{
    -0.4f, -0.6f * sqrt(3) / 3, 0.0f,
     0.6f, -0.4f * sqrt(3) / 3, 0.0f,
     0.0f,  0.3f * sqrt(3) * 2 / 3, 0.0f
};
```

These coordinates are uploaded to GPU memory through a Vertex Buffer Object (VBO).

---

# Concepts Demonstrated

- Modern OpenGL
- Graphics Context
- GPU Programming
- GLSL
- Vertex Shader
- Fragment Shader
- Shader Compilation
- Shader Linking
- Shader Program
- Vertex Buffer Object (VBO)
- Vertex Array Object (VAO)
- Vertex Attributes
- Primitive Assembly
- Rasterization
- Framebuffer
- Graphics Pipeline
- GPU Memory Management

---

# Learning Objectives

After completing this project, you should understand:

- Why Modern OpenGL requires shaders.
- How a shader program is created.
- The difference between a VBO and a VAO.
- How vertex data is transferred to the GPU.
- How OpenGL interprets vertex attributes.
- How a triangle is assembled and rasterized.
- The responsibilities of the Vertex Shader and Fragment Shader.
- The basic execution flow of the OpenGL rendering pipeline.

---

# Possible Extensions

This project can be extended by implementing:

- Indexed drawing (EBO)
- Multiple triangles
- Uniform variables
- Transformations
- Matrices
- Animation
- Colors per vertex
- Textures
- Camera system
- Lighting
- 3D models

---

# References

- LearnOpenGL
- OpenGL Specification
- GLFW Documentation
- GLAD Documentation

---

# License

This project was developed for educational purposes and learning Modern OpenGL.