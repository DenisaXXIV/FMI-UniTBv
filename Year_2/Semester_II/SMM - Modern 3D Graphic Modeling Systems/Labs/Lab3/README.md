# Lab3 - Uniform Variables

Welcome to the Uniform Variables! This repository is dedicated to providing you with code samples and resources to enhance your understanding and mastery of uniform variables in OpenGL using C++ and Visual Studio 2022.

Copyright - [DenisaXXIV](https://github.com/DenisaXXIV)

## About OpenGL

OpenGL (Open Graphics Library) is a powerful and widely-used cross-platform API (Application Programming Interface) for rendering 2D and 3D computer graphics. It provides developers with a set of functions and capabilities to interact with the GPU (Graphics Processing Unit) and create stunning visuals for various applications, including games, simulations, and scientific visualization.

You can find more: [here](%5Bhttps://www.opengl.org/%5D(https://www.opengl.org/))

## Laboratory Overview

In this folder, you will find a collection of code samples and projects that cover various aspects of uniform variables in OpenGL. The purpose of this repository was to guide me through the concepts, usage, and best practices related to working with uniform variables.

You can find more: [Laborator 3 - Variabile uniforme](https://docs.google.com/document/d/10X-7euu3HIKAjRw01hoagXeYEXjtDPAxbFQZ5WX4ogc/edit)

## Getting Started for Visual Studio 2022

<ol>
  <li><strong>Ensure you have Visual Studio 2022 installed on your system, </strong>as it provides an excellent development environment for C++ and OpenGL.</li>
  <li><strong>Download GLEW library:</strong> <a href="https://glew.sourceforge.net/">Download GLEW here</a></li>
  <li><strong>Download FreeGLUT library:</strong> <a href="https://freeglut.sourceforge.net/">Download FreeGLUT here</a></li>
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

It is required to build a 3D application in openGL that displays a triangle with the vertices of the color sister, green and blue. Change the code as follows:

1. Let the triangle move from left to right and from right to left, using a transformation matrix with translation on OX as the uniform variable.

2. Let the triangle move from bottom to top and from top to bottom, using a transformation matrix with translation on OY as the uniform variable.

3. The center of gravity of the triangle should move on a circular trajectory clockwise and counterclockwise, using a transformation matrix with translation on OX and OY as the uniform variable.

4. To rotate the triangle around the OZ axis, using a rotation matrix around the OZ axis as the uniform variable.

5. Scale the triangle, using a scaling matrix on OX and OY as the uniform variable.

| State      | Command | Window                                                                                                                                                                         |
| ---------- | ------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| Initial    | n       | ![](https://raw.githubusercontent.com/DenisaXXIV/FMI-UniTBv/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab3/resources/none.png)       |
| Horizontal | h       | ![](https://raw.githubusercontent.com/DenisaXXIV/FMI-UniTBv/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab3/resources/horizontal.gif) |
| Vertical   | v       | ![](https://raw.githubusercontent.com/DenisaXXIV/FMI-UniTBv/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab3/resources/vertical.gif)   |
| Circular   | c       | ![](https://raw.githubusercontent.com/DenisaXXIV/FMI-UniTBv/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab3/resources/circular.gif)   |
| Rotation   | z       | ![](https://raw.githubusercontent.com/DenisaXXIV/FMI-UniTBv/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab3/resources/rotations.gif)  |
| Scale      | s       | ![](https://raw.githubusercontent.com/DenisaXXIV/FMI-UniTBv/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab3/resources/scale.gif)      |

</br>
</br>
</br>
I hope that this repository helped you, for more details about me, you can access my website:  <a href="https://denisa-vasile.info/"> here </a>
