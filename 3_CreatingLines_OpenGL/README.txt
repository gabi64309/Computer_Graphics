# OpenGL – Rendering Lines

A minimal Modern OpenGL application written in C++ that demonstrates how to render multiple independent line segments using the programmable graphics pipeline.

Unlike previous examples that rendered points or triangles, this project focuses on the `GL_LINES` primitive, where every pair of vertices represents an independent line segment.

The rendered output forms a simple stylized face composed entirely of straight lines.

---

# Preview

```
      |       |

         |

      \____/
```

The image is composed of:

- Left eye
- Right eye
- Nose
- Three-line mouth

---

# Features

- Modern OpenGL 3.3 Core Profile
- GLFW window creation
- GLAD function loading
- Vertex Shader
- Fragment Shader
- Shader Program
- Vertex Buffer Object (VBO)
- Vertex Array Object (VAO)
- Rendering using `GL_LINES`
- Fullscreen rendering
- Fail-fast initialization

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
- OpenGL 3.3 compatible graphics card
- GLFW
- GLAD

---

# Building

Windows

```bash
g++ main.cpp -o Lines ^
-Iinclude ^
-Llib ^
-lglfw3 -lopengl32
```

Linux

```bash
g++ main.cpp -o Lines \
-lglfw \
-lGL \
-ldl \
-pthread
```

---

# How It Works

The application performs the following steps:

1. Initializes GLFW.
2. Creates an OpenGL Core Profile context.
3. Loads OpenGL functions through GLAD.
4. Compiles the Vertex Shader.
5. Compiles the Fragment Shader.
6. Links both shaders into a Shader Program.
7. Creates a Vertex Buffer Object (VBO).
8. Uploads all line vertices into GPU memory.
9. Creates and configures a Vertex Array Object (VAO).
10. Clears the framebuffer.
11. Renders six independent lines using `GL_LINES`.
12. Continues rendering until the window closes.

---

# Graphics Pipeline

```
Vertices
    │
    ▼
Vertex Shader
    │
    ▼
Primitive Assembly
(GL_LINES)
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

# Vertex Layout

Each line is defined by **exactly two vertices**.

```
Vertex 0 ───────── Vertex 1   → Line 1

Vertex 2 ───────── Vertex 3   → Line 2

Vertex 4 ───────── Vertex 5   → Line 3

...
```

Because the program renders six lines, the VBO contains twelve vertices.

---

# GL_LINES

When using

```cpp
glDrawArrays(GL_LINES, 0, 12);
```

OpenGL interprets the vertex data as:

```
v0 ─── v1

v2 ─── v3

v4 ─── v5

v6 ─── v7

v8 ─── v9

v10 ─── v11
```

Each pair of vertices produces one independent line.

---

# Concepts Demonstrated

- Modern OpenGL
- Graphics Pipeline
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
- GL_LINES
- Rasterization
- Framebuffer
- GPU Memory Management

---

# Learning Objectives

After completing this example, you should understand:

- How OpenGL renders independent line segments.
- Why `GL_LINES` requires two vertices per line.
- How vertex data is uploaded to GPU memory.
- The responsibilities of the Vertex Shader.
- The responsibilities of the Fragment Shader.
- The role of VAOs and VBOs.
- How the graphics pipeline converts vertices into rendered line primitives.

---

# Comparison of Basic OpenGL Primitives

| Primitive | Vertices Required | Description |
|-----------|------------------:|------------|
| `GL_POINTS` | 1 per point | Renders individual points. |
| `GL_LINES` | 2 per line | Renders independent line segments. |
| `GL_LINE_STRIP` | N | Connects each vertex to the next. |
| `GL_LINE_LOOP` | N | Like `GL_LINE_STRIP`, but closes the shape. |
| `GL_TRIANGLES` | 3 per triangle | Renders independent triangles. |

---

# Possible Extensions

This project can be extended by implementing:

- Line strips
- Line loops
- Wireframe polygons
- Variable line widths
- Vertex colors
- Uniform variables
- Transformations
- Animation
- Indexed drawing (EBO)
- 2D vector graphics

---

# References

- LearnOpenGL
- OpenGL 4.6 Specification
- GLFW Documentation
- GLAD Documentation

---

# License

This project was developed for educational purposes and as an introduction to Modern OpenGL line rendering.