# Lab8 - Shadow Mapping

Welcome to the "Lab8 - Shadow Mapping"! This repository is designed to help you learn about shadow mapping techniques in OpenGL using C++ and Visual Studio 2022. 

Copyright - [DenisaXXIV](https://github.com/DenisaXXIV)

## About OpenGL

OpenGL (Open Graphics Library) is a powerful and widely-used cross-platform API (Application Programming Interface) for rendering 2D and 3D computer graphics. It provides developers with a set of functions and capabilities to interact with the GPU (Graphics Processing Unit) and create stunning visuals for various applications, including games, simulations, and scientific visualization.

You can find more: [here](%5Bhttps://www.opengl.org/%5D(https://www.opengl.org/))

## About Shadow Mapping in OpenGL

Shadow mapping is a widely used technique in computer graphics to simulate realistic shadows in 3D scenes. It involves the generation and rendering of a depth map from the perspective of a light source, capturing the distance from the light to each visible point in the scene. By comparing this depth map with the depth of each fragment during the final rendering pass, shadows can be accurately determined and applied to the scene. Shadow mapping allows for the creation of dynamic and interactive shadows, enhancing the visual realism and depth perception of virtual environments in OpenGL.

## Laboratory Overview

In this folder, you will find a collection of code samples and projects that cover various aspects of working with shadow mapping in OpenGL.

You can find more: [Laborator 8 - Shadow Mapping](https://docs.google.com/document/d/1_pXNPZqsRKkLRvJKFlN2cLpWnO3oukG5UwYqyNJu3T4/edit)

## Texture Attribution

Here are the links to the websites where you can find more textures:

1. Texture 1: [Link to floor texture](https://www.textures.com/download/3DScans0128/132311?seamless=130316)

2. Texture 2: [Link to concrete pavement tiles texture ](https://www.textures.com/download/PBR0682/139217?seamless=147161)

3. Texture 3: [Link to parquet texture]((https://www.textures.com/download/PBR0473/138363?seamless=144488)

4. Freepik: [here](https://www.freepik.com/)

5. Textures.com: [here](https://www.textures.com/)

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

It is required to build a 3D application in openGL, to create the Phong model of light with the components: ambient, diffuse and specular and to map the shadows. Change the code as follows:

1. Let the light rotate in a circle with a radius of 2.0 in the xOz plane. When pressing the "L" key, the light rotates and when pressing the "S" key, the light stops rotating.

2. Display another 3 cubes in the renderScene method with various positions and orientations.

3. To solve the problem of acne using a hardcoded bias.

4. To eliminate the artifacts outside the frustrum of the light source.

5. Increase the texture size from 1024X1024 to 4096X4096.

6. Calculate a bias according to the direction of the camera and the normal.

7. Reduce the size of the shadow to 1024X1024 and make a PCF (Percentage-Closer Filter) filter.

| Initial              | ![](https://github.com/DenisaXXIV/FMI-UniTBv/blob/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab8/resources/initial.gif?raw=true)         |
| -------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Pressing "L" key** | ![](https://github.com/DenisaXXIV/FMI-UniTBv/blob/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab8/resources/light%20rotates.gif?raw=true) |
| **Pressing "S" key** | ![](https://github.com/DenisaXXIV/FMI-UniTBv/blob/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab8/resources/light%20stops.gif?raw=true)   |
| **4 Cubes**          | ![](https://github.com/DenisaXXIV/FMI-UniTBv/blob/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab8/resources/4%20cubes.gif?raw=true)       |

</br>
</br>
</br>
I hope that this repository helped you, for more details about me, you can access my website:  <a href="https://denisa-vasile.info/"> here </a>
