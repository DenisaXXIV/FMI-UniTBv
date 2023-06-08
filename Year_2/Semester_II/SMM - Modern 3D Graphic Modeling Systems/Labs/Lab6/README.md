# Lab6 - Textures

Welcome to the OpenGL Textures! This repository is dedicated to providing you with code samples and resources to enhance your understanding and skills in working with textures in OpenGL using C++ and Visual Studio 2022.

Copyright - [DenisaXXIV](https://github.com/DenisaXXIV)

## About OpenGL

OpenGL (Open Graphics Library) is a powerful and widely-used cross-platform API (Application Programming Interface) for rendering 2D and 3D computer graphics. It provides developers with a set of functions and capabilities to interact with the GPU (Graphics Processing Unit) and create stunning visuals for various applications, including games, simulations, and scientific visualization.

You can find more: [here](%5Bhttps://www.opengl.org/%5D(https://www.opengl.org/))

## About Textures in OpenGL

Textures play a vital role in adding visual details and realism to 3D graphics in OpenGL. They enable you to apply images or patterns onto surfaces, simulate materials and create immersive environments. Understanding how to load, manipulate, and utilize textures is essential for creating visually appealing and engaging graphics applications.

## Laboratory Overview

In this folder, you will find a collection of code samples and projects that cover various aspects of working with textures in OpenGL. The repository aimed to guide me through the concepts, techniques and best practices for texture handling and mapping.

You can find more: [Laborator 6 - Texturi](https://docs.google.com/document/d/1ylDPDJs3Jswr1UxIyGq3JZG--qj9qqLSA9221js5bRE/edit)

## Texture Attribution

Here are the links to the websites where you can find more textures:

1. Texture 1: [Link to stone wall texture](https://www.freepik.com/free-photo/stone-wall_1150976.htm#query=stone%20texture&position=42&from_view=keyword&track=ais#position=42&query=stone%20texture)

2. Freepik: [here](https://www.freepik.com/)

3. Textures.com: [here](https://www.textures.com/)

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

It is required to build a 3D application in OpenGL, to display 9 colored rectangles, and to rotate the camera around the center of the scene. Change the code so that:

1. Download two textures.

2. Change the value of the uniform variable for the mixing factor in the fragment shader.

3. When pressing the "i" key, increase the value of the mixing factor up to the maximum "1".

4. When pressing the "d" key, increase the value of the mixing factor up to the maximum "0".

5. To multiply the color of the textures with the color of the peaks.

6. Draw a pyramid. Apply the texture to all faces of the pyramid.

7. Draw a cube. Apply the texture to all faces of the cube.

|         | Presentation                                                                                                                                                                        | Maxim factor up                                                                                                                                                                             | Maxim factor down                                                                                                                                                                           |
| ------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Square  | ![](https://raw.githubusercontent.com/DenisaXXIV/FMI-UniTBv/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab6/resources/square/square.gif)   | ![](https://raw.githubusercontent.com/DenisaXXIV/FMI-UniTBv/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab6/resources/square/square%20-%20i.gif)   | ![](https://raw.githubusercontent.com/DenisaXXIV/FMI-UniTBv/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab6/resources/square/square%20-%20d.gif)   |
| Piramid | ![](https://raw.githubusercontent.com/DenisaXXIV/FMI-UniTBv/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab6/resources/piramid/piramid.gif) | ![](https://raw.githubusercontent.com/DenisaXXIV/FMI-UniTBv/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab6/resources/piramid/piramid%20-%20i.gif) | ![](https://raw.githubusercontent.com/DenisaXXIV/FMI-UniTBv/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab6/resources/piramid/piramid%20-%20d.gif) |
| Cub     | ![](https://raw.githubusercontent.com/DenisaXXIV/FMI-UniTBv/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab6/resources/cub/cub.gif)         | ![](https://raw.githubusercontent.com/DenisaXXIV/FMI-UniTBv/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab6/resources/cub/cub%20-%20i.gif)         | ![](https://raw.githubusercontent.com/DenisaXXIV/FMI-UniTBv/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab6/resources/cub/cub%20-%20d.gif)         |
| Prism   | ![](https://raw.githubusercontent.com/DenisaXXIV/FMI-UniTBv/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab6/resources/prism/prism.gif)     | ![](https://raw.githubusercontent.com/DenisaXXIV/FMI-UniTBv/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab6/resources/prism/prism%20-%20i.gif)     | ![](https://raw.githubusercontent.com/DenisaXXIV/FMI-UniTBv/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab6/resources/prism/prism%20-%20d.gif)     |

</br>
</br>
</br>
I hope that this repository helped you, for more details about me, you can access my website:  <a href="https://denisa-vasile.info/"> here </a>
