# Lab5 - Interactive Room

Welcome to the OpenGL Interactive Room! This repository is dedicated to providing you with code samples and resources to enhance your understanding and skills in creating an interactive room using OpenGL, C++ and Visual Studio 2022.

Copyright - [DenisaXXIV](https://github.com/DenisaXXIV)

## About OpenGL

OpenGL (Open Graphics Library) is a powerful and widely-used cross-platform API (Application Programming Interface) for rendering 2D and 3D computer graphics. It provides developers with a set of functions and capabilities to interact with the GPU (Graphics Processing Unit) and create stunning visuals for various applications, including games, simulations, and scientific visualization.

You can find more: [here](%5Bhttps://www.opengl.org/%5D(https://www.opengl.org/))

## About Interactive Room

An interactive room in OpenGL refers to a virtual environment where users can navigate and interact with the surroundings. It typically involves rendering a 3D room with various objects, implementing user controls for movement and interaction, and incorporating visual and audio effects to create an immersive experience.

## Laboratory Overview

In this folder,you will find a collection of code samples and projects that cover various aspects of creating an interactive room in OpenGL. The repository was designed to guide me through the concepts, techniques, and best practices for building interactive environments using OpenGL.

You can find more: [Laborator 5 - Camera interactiva](https://docs.google.com/document/d/1hRJHu1qAHkIcre5gYzL3H2xDd5nspU0ITuwicDa54E0/edit)

## Getting Started for Visual Studio 2022

<ol>
  <li><strong>Ensure you have Visual Studio 2022 installed on your system, </strong>as it provides an excellent development environment for C++ and OpenGL.</li>
  <li><strong>Download GLEW library:</strong> <a href="https://glew.sourceforge.net/">Download GLEW here</a></li>
  <li><strong>Download FreeGLUT library:</strong> <a href="https://freeglut.sourceforge.net/">Download FreeGLUT here</a></li>
  <li><strong>Download GLM library:</strong> <a href="https://glm.g-truc.net/0.9.9/index.html">Download GLM here</a></li>
  <li><strong>Download GLFW library:</strong> <a href="https://www.glfw.org/">Download GLFW here</a></li>
  <li><strong>Create a Windows Console C++ Project in VS 2022</strong></li>
  <li><strong>Make an "External" directory:</strong> inside the folder that contains the .sln file create a new directory with the name "External"</li>
  <li><strong>Move the downloaded libraries in External directory:</strong> move unzipped folders to the "External" directory created in the previous step</li>
   <li><strong>Create a Windows Console C++ Project in VS 2022</strong></li>
  <li><strong>Move the .dll files to the directory that contains your classes:</strong> you cand find the .dll files in bin\Release\x64</li>
  <li><strong>Edit your Project Properties in your VS:</strong>
    <ul>
      <li><strong>C/C++ -> General -> Additional Include Directories:</strong> here add the include directories</li>
      <li><strong>Linker -> General -> Additional Library Directories:</strong> here add the lib\Release\x64 directories</li>
      <li><strong>Linker -> Input -> Additional Dependencies:</strong> here add the .dll files added at step 7, but with .lib extension, not .dll</li>
    </ul>
  </li>
</ol>

## Command Workflow Showcase

It is required to build a 3D application in OpenGL that displays 9 colored cubes, and the camera rotates around the cube in the center of the scene. Change the code as follows:

1. Let the camera move: forward, backward, left, right, up, down.

2. To bring the camera to the initial position and orientation when the "R" key is pressed.

3. To rotate the camera according to the movement of the cursor.

4. To achieve the zoom effect when moving the mouse wheel.
   
   ![](https://raw.githubusercontent.com/DenisaXXIV/FMI-UniTBv/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab5/resources/interactive%20room.gif)

</br>
</br>
</br>
I hope that this repository helped you, for more details about me, you can access my website:  <a href="https://denisa-vasile.info/"> here </a>
