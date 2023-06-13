# Lab7 - Light

This repository serves as a showcase of my learning journey in lighting  techniques using OpenGL, implemented in C++ with Visual Studio 2022. It features a project that demonstrate various lighting concepts and effects, allowing you to explore the visual impact of different lighting techniques in a real-time 3D scene.

You can find more: [Laborator 7 - Lumina](https://docs.google.com/document/d/1Mb_xuvvnYVFWjL8huZKaxI_4P1odMAdzHfbUq7yA6Sk/edit)

Copyright - [DenisaXXIV](https://github.com/DenisaXXIV)

## About OpenGL

OpenGL (Open Graphics Library) is a powerful and widely-used cross-platform API (Application Programming Interface) for rendering 2D and 3D computer graphics. It provides developers with a set of functions and capabilities to interact with the GPU (Graphics Processing Unit) and create stunning visuals for various applications, including games, simulations, and scientific visualization.

You can find more: [here](%5Bhttps://www.opengl.org/%5D(https://www.opengl.org/))

## About Light in OpenGL

In OpenGL, lighting plays a crucial role in creating realistic 3D scenes. By applying light sources, such as directional, point, or spotlights, developers can enhance the visual depth, shadows, and overall ambiance of their OpenGL projects, bringing them to life.

## Laboratory Overview

![](https://github.com/DenisaXXIV/FMI-UniTBv/blob/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab7/resources/Lab7%20-%20Presentation.gif?raw=true)

## Getting Started for Visual Studio 2022

<ol>
  <li><strong>Ensure you have Visual Studio 2022 installed on your system, </strong>as it provides an excellent development environment for C++ and OpenGL.</li>
  <li><strong>Download GLEW library:</strong> <a href="https://glew.sourceforge.net/">Download GLEW here</a></li>
  <li><strong>Download FreeGLUT library:</strong> <a href="https://freeglut.sourceforge.net/">Download FreeGLUT here</a></li>
  <li><strong>Download GLM library:</strong> <a href="https://glm.g-truc.net/0.9.9/index.html">Download GLM here</a></li>
  <li><strong>Download GLFW library:</strong> <a href="https://www.glfw.org/">Download GLFW here</a></li>
  <li><strong>Download STB image libraries:</strong> <a href="https://github.com/nothings/stb">Download STB image libraries here</a></li>  
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

## Environmental Reflection

| a (-)                                                                                                                                                                           | z (+)                                                                                                                                                                           |
|:-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------:|:-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------:|
| ![](https://github.com/DenisaXXIV/FMI-UniTBv/blob/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab7/resources/Lab7%20-%20a.gif?raw=true) | ![](https://github.com/DenisaXXIV/FMI-UniTBv/blob/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab7/resources/Lab7%20-%20z.gif?raw=true) |

## Diffuse Reflection

| d (-)                                                                                                                                                                           | c (+)                                                                                                                                                                           |
|:-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------:|:-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------:|
| ![](https://github.com/DenisaXXIV/FMI-UniTBv/blob/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab7/resources/Lab7%20-%20d.gif?raw=true) | ![](https://github.com/DenisaXXIV/FMI-UniTBv/blob/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab7/resources/Lab7%20-%20c.gif?raw=true) |

## Specular reflection

| s (-)                                                                                                                                                                           | x (+)                                                                                                                                                                           |
|:-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------:|:-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------:|
| ![](https://github.com/DenisaXXIV/FMI-UniTBv/blob/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab7/resources/Lab7%20-%20s.gif?raw=true) | ![](https://github.com/DenisaXXIV/FMI-UniTBv/blob/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab7/resources/Lab7%20-%20x.gif?raw=true) |

## Specular Reflection Exponent

| e (-)                                                                                                                                                                           | f (+)                                                                                                                                                                           |
|:-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------:|:-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------:|
| ![](https://github.com/DenisaXXIV/FMI-UniTBv/blob/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab7/resources/Lab7%20-%20e.gif?raw=true) | ![](https://github.com/DenisaXXIV/FMI-UniTBv/blob/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab7/resources/Lab7%20-%20f.gif?raw=true) |



</br>
</br>
</br>
I hope that this repository helped you, for more details about me, you can access my website:  <a href="https://denisa-vasile.info/"> here </a>
