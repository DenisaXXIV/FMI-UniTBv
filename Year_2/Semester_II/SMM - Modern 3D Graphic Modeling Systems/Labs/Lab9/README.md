# Lab9 - Blending

Welcome to the "Lab9 - Blending"! This repository is designed to help you learn about blending techniques in OpenGL using C++ and Visual Studio 2022. 

Copyright - [DenisaXXIV](https://github.com/DenisaXXIV)

## About OpenGL

OpenGL (Open Graphics Library) is a powerful and widely-used cross-platform API (Application Programming Interface) for rendering 2D and 3D computer graphics. It provides developers with a set of functions and capabilities to interact with the GPU (Graphics Processing Unit) and create stunning visuals for various applications, including games, simulations, and scientific visualization.

You can find more: [here](%5Bhttps://www.opengl.org/%5D(https://www.opengl.org/))

## About Blending in OpenGL

Blending is a fundamental technique in computer graphics that enables the combination of multiple fragments to create smooth and transparent visuals. In OpenGL, blending involves the computation of a final pixel color based on the source and destination colors, using blending factors and equations. Understanding the concept of alpha blending is crucial, as it allows for the seamless integration of transparent objects and textures. By manipulating blending factors and equations, developers can achieve various effects, such as additive blending for light sources or multiplicative blending for shadows. Mastering blending theory empowers developers to create visually stunning and realistic graphics in OpenGL.

## Laboratory Overview

In this folder, you will find a collection of code samples and projects that cover various aspects of working with blending in OpenGL. It provides a step-by-step tutorial and project that demonstrates blending effects by combining grass with a square mud texture.

You can find more: [Laborator 9 - Blending](https://docs.google.com/document/d/1PohRyh1CYFBlMTbbzyMf2hL1nHhB3HNH5apkzoQW18I/edit)

## Texture Attribution

Here are the links to the websites where you can find more textures:

1. Texture 1: [Link to mud texture]([Textures for 3D, graphic design and Photoshop!](https://www.textures.com/download/3DScans0128/132311?seamless=130316))

2. Texture 2: [Link to grass texture](https://www.clipartmax.com/download/m2i8Z5i8H7K9b1G6_free-icons-png-grass-alpha-texture-png/#)

3. Freepik: [here](https://www.freepik.com/)

4. Textures.com: [here](https://www.textures.com/)

5. ClipArtMax: [here](https://www.clipartmax.com/)

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

## Command Workflow Showcase

It is required to build a 3D application in openGL, which will display a field of grass consisting of textures with an Alpha channel. Change the code as follows:

1. Create VBO and VAO for a 5X5 size parquet with -0.5 elevation consisting of geometry and texture coordinates. A texture with the name "ColoredFloor.png" is applied over this surface. Create a file "floor.vs" and a file "floor.fs", to be used for rendering the parquet.

2. In the center of the parquet, grass should be displayed on a 0.5X0.5 square using the "grass3.png" texture. Create a file "blending.vs" and "blending.fs" to be used for rendering the grass.

3. A network of squares with grass should be displayed on the entire surface of the parquet.

4. Display a tuft of grass in the center of the scene.

5. To display a network of tufts of grass.

| Floor                       | ![](https://github.com/DenisaXXIV/FMI-UniTBv/blob/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab9/resources/mud.gif?raw=true)          |
| --------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Tuft of Grass**           | ![](https://github.com/DenisaXXIV/FMI-UniTBv/blob/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab9/resources/grass.gif?raw=true)        |
| **Tufts of Grass Network**  | ![](https://github.com/DenisaXXIV/FMI-UniTBv/blob/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab9/resources/net-of-grass.gif?raw=true) |
| **Tuft of Grass & Flower*** | ![](https://github.com/DenisaXXIV/FMI-UniTBv/blob/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab9/resources/grass&flower.gif?raw=true) |

</br>
</br>
</br>
I hope that this repository helped you, for more details about me, you can access my website:  <a href="https://denisa-vasile.info/"> here </a>
