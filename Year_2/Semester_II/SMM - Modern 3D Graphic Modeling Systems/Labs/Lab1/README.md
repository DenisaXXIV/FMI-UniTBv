# Lab1 - OpenGL Fixed Pipes and Shader

Welcome to the OpenGL Fixed Pipes and Shader! This part of the repository is designed to provide you with the hands-on learning experience that i had for both fixed-function pipelines and shaders in OpenGL using C++ and Visual Studio 2022.

Copyright - [DenisaXXIV](https://github.com/DenisaXXIV)

## About OpenGL

OpenGL (Open Graphics Library) is a powerful and widely-used cross-platform API (Application Programming Interface) for rendering 2D and 3D computer graphics. It provides developers with a set of functions and capabilities to interact with the GPU (Graphics Processing Unit) and create stunning visuals for various applications, including games, simulations, and scientific visualization.

You can find more: [here](%5Bhttps://www.opengl.org/%5D(https://www.opengl.org/))

## Laboratory Overview

In this folder, you will find a collection of code samples and projects that cover both the traditional fixed-function pipeline and the modern shader-based approach in OpenGL. The purpose of this laboratory was to help me understand and compare the two techniques, allowing me to make informed decisions when designing and implementing my future graphics applications.

You can find more: [Laborator 1 - Hello OpenGL](https://docs.google.com/document/d/1nLhLVaYt1ExojOA-wbWUkgFMjVlxDk7ZceTFp00eISY/edit)

## Getting Started for Visual Studio 2022

<ol>
  <li><strong>Ensure you have Visual Studio 2022 installed on your system, </strong>as it provides an excellent development environment for C++ and OpenGL.</li>
  <li><strong>Download GLEW library:</strong> <a href="https://glew.sourceforge.net/">Download GLEW here</a></li>
  <li><strong>Download FreeGLUT library:</strong> <a href="https://freeglut.sourceforge.net/">Download FreeGLUT here</a></li>
  <li><strong>Download GLM library:</strong> <a href="https://glm.g-truc.net/0.9.9/index.html">Download GLM here</a></li>
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

## Comparision

It is required to build a 3D application in OpenGL using the old way of working with the fixed pipe and the new way of working with shaders to display three vertices of the red, green and blue triangle. 

1. Change the code for old OpenGL so that you have an X made of 5 green dots on the blue screen. 

2. Change the code for the new OpenGL so that you have 3 collinear green points on the red area.

|         | Fixed pipe                                                                                                                                                                     | Shaders                                                                                                                                                                        |
| ------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| Initial | ![](https://raw.githubusercontent.com/DenisaXXIV/FMI-UniTBv/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab1/resources/old.png)        | ![](https://raw.githubusercontent.com/DenisaXXIV/FMI-UniTBv/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab1/resources/new.png)        |
| Solved  | ![](https://raw.githubusercontent.com/DenisaXXIV/FMI-UniTBv/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab1/resources/old-solved.png) | ![](https://raw.githubusercontent.com/DenisaXXIV/FMI-UniTBv/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab1/resources/new-solved.png) |

<br>

<br>

</br>
</br>
</br>
I hope that this repository helped you, for more details about me, you can access my website:  <a href="https://denisa-vasile.info/"> here </a>
