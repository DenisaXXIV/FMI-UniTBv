# Lab4 - Projections and Primitive Indexing

Welcome to the OpenGL Projections and Primitive Indexing! This part of the repository is dedicated to providing you with code samples and resources that i use to to enhance my understanding and mastery of projections and primitive indexing in OpenGL using C++ and Visual Studio 2022.

Copyright - [DenisaXXIV](https://github.com/DenisaXXIV)

## About OpenGL

OpenGL (Open Graphics Library) is a powerful and widely-used cross-platform API (Application Programming Interface) for rendering 2D and 3D computer graphics. It provides developers with a set of functions and capabilities to interact with the GPU (Graphics Processing Unit) and create stunning visuals for various applications, including games, simulations, and scientific visualization.

You can find more: [here](%5Bhttps://www.opengl.org/%5D(https://www.opengl.org/))

## About Projections and Primitive Indexing

Projections and primitive indexing are fundamental concepts in computer graphics that allow you to manipulate the view and presentation of 3D objects on a 2D screen. Projections help create realistic perspectives and handle transformations, while primitive indexing allows efficient rendering of complex geometry by reusing shared vertices.

## Laboratory Overview

In this folder,you will find a collection of code samples and projects that cover various aspects of projections and primitive indexing in OpenGL. The purpose of this repository was to guide me through the concepts, techniques, and best practices related to these fundamental graphics topics.

You can find more: [Laborator 4 - Proiectii si indexarea primitivelor](https://docs.google.com/document/d/1-km78CXqf1-SyNwhoZjx3wddrzAjrQcJTvhLIPPxYOU/edit)

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

## Command Workflow Showcase

It is required to build a 3D application in OpenGL that displays a pyramid with red, green and blue vertices. Change the code as follows:

1. When the "W" key is pressed, the pyramid will be displayed using lines (wireframe). When the "S" key is pressed, it returns to the solid representation of the pyramid.

2. To implement a method that returns the projection matrix. The method will receive as parameter bOrthoProj of boolean type. IfcabOrthoProj is true, the method will return the orthographic projection matrix, otherwise it will return the perspective projection matrix. The difference between orthographic projection and perspective projection is best seen in the wireframe representation.

3. For perspective projection, modify FieldOfView. When the "I" key is pressed, FieldOfView will be incremented and when the "D" key is pressed, it will be decremented. The FieldOfView modification is used for the zoom effect.

4. Replace the pyramid with a cube made of 12 triangles.

| State     | Command | Piramid                                                                                                                                                                             | Prism                                                                                                                                                                             | Cub                                                                                                                                                                             |
| --------- | ------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Solid     | S       | ![](https://raw.githubusercontent.com/DenisaXXIV/FMI-UniTBv/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab4/resources/piramid%20-%20s.gif) | ![](https://raw.githubusercontent.com/DenisaXXIV/FMI-UniTBv/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab4/resources/prism%20-%20s.gif) | ![](https://raw.githubusercontent.com/DenisaXXIV/FMI-UniTBv/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab4/resources/cub%20-%20s.gif) |
| Wireframe | W       | ![](https://raw.githubusercontent.com/DenisaXXIV/FMI-UniTBv/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab4/resources/piramid%20-%20w.gif) | ![](https://raw.githubusercontent.com/DenisaXXIV/FMI-UniTBv/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab4/resources/prism%20-%20w.gif) | ![](https://raw.githubusercontent.com/DenisaXXIV/FMI-UniTBv/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab4/resources/cub%20-%20w.gif) |
| Zoom In   | I       | ![](https://raw.githubusercontent.com/DenisaXXIV/FMI-UniTBv/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab4/resources/piramid%20-%20i.gif) | ![](https://raw.githubusercontent.com/DenisaXXIV/FMI-UniTBv/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab4/resources/prism%20-%20i.gif) | ![](https://raw.githubusercontent.com/DenisaXXIV/FMI-UniTBv/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab4/resources/cub%20-%20i.gif) |
| Zoom Out  | D       | ![](https://raw.githubusercontent.com/DenisaXXIV/FMI-UniTBv/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab4/resources/piramid%20-%20d.gif) | ![](https://raw.githubusercontent.com/DenisaXXIV/FMI-UniTBv/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab4/resources/prism%20-%20d.gif) | ![](https://raw.githubusercontent.com/DenisaXXIV/FMI-UniTBv/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab4/resources/cub%20-%20d.gif) |

</br>
</br>
</br>
I hope that this repository helped you, for more details about me, you can access my website:  <a href="https://denisa-vasile.info/"> here </a>
