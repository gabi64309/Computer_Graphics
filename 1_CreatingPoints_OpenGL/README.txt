# OpenGL - Rendering Points

A minimal modern OpenGL application written in C++ that demonstrates how to render geometric primitives as points using the programmable graphics pipeline.

This project initializes an OpenGL 3.3 Core Profile context with GLFW, loads OpenGL functions using GLAD, creates and links GLSL shaders, uploads vertex data through a Vertex Buffer Object (VBO), configures a Vertex Array Object (VAO), and renders three vertices as `GL_POINTS`.

---

## Features

- Modern OpenGL (3.3 Core Profile)
- GLFW window and context creation
- GLAD OpenGL function loader
- Vertex Shader
- Fragment Shader
- Shader compilation and linking
- Vertex Buffer Object (VBO)
- Vertex Array Object (VAO)
- Rendering with `GL_POINTS`
- Configurable point size using `gl_PointSize`
- Basic fail-fast error handling

---

## Project Structure

```
.
├── main.cpp
├── glad/
├── GLFW/
└── README.md
```

---

## Requirements

- C++17 or later
- OpenGL 3.3+
- GLFW
- GLAD

---

## Building

Compile and link against GLFW and OpenGL.

Example:

```bash
g++ main.cpp -lglfw -lopengl32
```

Linux:

```bash
g++ main.cpp -lglfw -lGL -ldl -pthread
```

> The exact command depends on your compiler and operating system.

---

## How It Works

The application performs the following steps:

1. Initializes GLFW.
2. Creates an OpenGL 3.3 Core Profile context.
3. Loads OpenGL functions through GLAD.
4. Compiles the vertex and fragment shaders.
5. Links both shaders into a shader program.
6. Creates a VBO containing three vertices.
7. Configures a VAO describing the vertex layout.
8. Clears the framebuffer.
9. Draws the vertices as points.
10. Swaps buffers until the window closes.

---

## Graphics Pipeline

```
Vertices
    │
    ▼
Vertex Shader
    │
    ▼
Primitive Assembly (Points)
    │
    ▼
Rasterization
    │
    ▼
Fragment Shader
    │
    ▼
Framebuffer
```

---

## Output

The program renders:

- Three orange points
- Dark blue background
- Point size controlled in the vertex shader

---

## Concepts Demonstrated

- Modern OpenGL
- GPU Programming
- GLSL
- Shader Pipeline
- Vertex Processing
- Fragment Processing
- VBO
- VAO
- Graphics Context
- Primitive Rendering
- GPU Resource Management

---

## Learning Objectives

After completing this example, you should understand:

- Why modern OpenGL requires shaders.
- The purpose of VAOs and VBOs.
- The role of the graphics pipeline.
- How vertex data reaches the GPU.
- How a shader program is created and executed.
- How OpenGL renders points instead of triangles.

---

## License

This project is intended for educational purposes.