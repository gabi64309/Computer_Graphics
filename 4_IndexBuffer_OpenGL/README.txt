Description

This project demonstrates how to render geometry efficiently in Modern OpenGL (Core Profile 3.3) by introducing an Element Buffer Object (EBO), also known as an Index Buffer. Instead of duplicating vertex data for every triangle, an EBO stores indices that reference vertices already contained in a Vertex Buffer Object (VBO). This approach reduces memory usage, minimizes data transfer to the GPU, and allows multiple primitives to share the same vertices.

The program creates an OpenGL context using GLFW, loads OpenGL function pointers with GLAD, compiles a basic vertex and fragment shader, uploads vertex and index data to GPU memory, configures a Vertex Array Object (VAO), and renders the geometry using glDrawElements().

Learning Objectives
Understand the purpose of an Element Buffer Object (EBO).
Learn how indexed rendering differs from glDrawArrays().
Reduce duplicated vertex data by sharing vertices among multiple triangles.
Understand the relationship between VAO, VBO, and EBO.
Render indexed geometry using glDrawElements().
Technologies
C++
OpenGL 3.3 Core Profile
GLFW
GLAD
Rendering Pipeline

The rendering process follows these steps:

Initialize GLFW and create an OpenGL context.
Load OpenGL functions with GLAD.
Compile the vertex and fragment shaders.
Create a VAO.
Create and fill the VBO with vertex data.
Create and fill the EBO with index data.
Configure the vertex attributes.
Render the indexed geometry using glDrawElements().
Release GPU resources before exiting.
Why Use an Index Buffer?

Without an index buffer, every triangle must repeat the coordinates of vertices that are shared with neighboring triangles. As a model grows in complexity, this duplication significantly increases memory consumption.

An Element Buffer Object (EBO) solves this problem by storing each unique vertex only once. Triangles are then described using indices that reference those vertices.