# Lab2 - DirectX 9 vs DirectX 11

Welcome to the DirectX 9 vs DirectX 11! This part of the repository is designed to provide you with the hands-on learning experience that i had for both DirecX 9 and DirectX 11 using C++ and Visual Studio 2022.

Copyright - [DenisaXXIV](https://github.com/DenisaXXIV)

## About DirectX

DirectX is a collection of APIs developed by Microsoft that provides a 
comprehensive set of tools and libraries for multimedia and game 
development on the Windows platform. It includes various components for 
handling graphics, audio, input, and networking, with a specific focus 
on providing efficient and hardware-accelerated 3D rendering 
capabilities.

You can find more: [here](https://www.microsoft.com/en-us/download/details.aspx?id=35)

## Laboratory Overview

Within this folder, you will find informative documents, code samples, 
and projects related to DirectX9 and DirectX 11. The purpose of this 
overview was to introduce me to the key concepts, features, and 
techniques associated with these versions of DirectX.

You can find more here: [Laborator 2 - Hello DirectX](https://docs.google.com/document/d/1nUMHyPlBQhy0bnadcyjUlUIZSb_acTHaoTJ-CYDRADQ/edit)

## Getting Started for Visual Studio 2022

1. **Ensure you have Visual Studio 2022 installed on your system,** as it provides an excellent development environment for C++ and OpenGL.
2. **Download GLEW library:** [Download GLEW here](https://glew.sourceforge.net/)
3. **Download FreeGLUT library:** [Download FreeGLUT here](https://freeglut.sourceforge.net/)
4. **Create a Windows Console C++ Project in VS 2022**
5. **Make an "External" directory:** inside the folder that contains the .sln file create a new directory with the name "External"
6. **Move the downloaded libraries in External directory:** move unzipped folders to the "External" directory created in the previous step
7. **Create a Windows Console C++ Project in VS 2022**
8. **Move the .dll files to the directory that contains your classes:** you cand find the .dll files in bin\Release\x64
9. **Edit your Project Properties in your VS:**
   - **C/C++ -> General -> Additional Include Directories:** here add the include directories
   - **Linker -> General -> Additional Library Directories:** here add the lib\Release\x64 directories
   - **Linker -> Input -> Additional Dependencies:** here add the .dll files added at step 7, but with .lib extension, not .dll

I hope that this repository helped you, for more details about me, you can access my website: [here](https://denisa-vasile.info/)

## Comparision

1. Modify the code for DirectX 9 so that the triangle is drawn on a green background at 10% from the edges of the window. 

2. Change the code for DirectX 11 so that you have an hourglass on an orange background.

|         | DirecX 9                                                                                                                                                                                                                                                     | DirectX 11 |
| ------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ | ---------- |
| Initial | <img src="https://raw.githubusercontent.com/DenisaXXIV/FMI-UniTBv/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab2/resources/DirecX%209.png" width="275" height="208"/>                                              |            |
| Solved  | <img title="" src="https://raw.githubusercontent.com/DenisaXXIV/FMI-UniTBv/master/Year_2/Semester_II/SMM%20-%20Modern%203D%20Graphic%20Modeling%20Systems/Labs/Lab2/resources/DirecX%209%20-%20solved.png" alt="DirecX 9 - solved" width="275" height="208"> |            |
