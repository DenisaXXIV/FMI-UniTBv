# SMM - Modern 3D Graphic Modeling Systems with C++
"Modern 3D Graphic Modeling Systems with C++" is a comprehensive course that teaches the principles of 3D modeling using C++. Students learn key concepts 
like transformations, lighting, shading, and rendering. The course focuses on using OpenGL, glew, and freeglut libraries to create visually captivating 3D 
environments. Through hands-on assignments, students apply theoretical knowledge and build a portfolio of projects. The course is ideal for aspiring professionals
in gaming, virtual reality, and computer-aided design, providing them with the necessary skills to explore the possibilities of 3D graphic modeling.

Copyright - [DenisaXXIV](https://github.com/DenisaXXIV)


## Configure Visual Studio 2022 for Graphic Modeling Systems with C++

<ol>
  <li><strong>Download glew library:</strong> <a href="https://glew.sourceforge.net/">Download glew here</a></li>
  <li><strong>Download freeglut library:</strong> <a href="https://freeglut.sourceforge.net/">Download freeglut here</a></li>
  <li><strong>Create a Windows Console C++ Project in VS 2022</strong></li>
  <li><strong>Make an "External" directory:</strong> inside the folder that contains the .sln file create a new directory with the name "External"</li>
  <li><strong>Move glew and freeglut in External directory:</strong> move unzipped folders of glew and freeglut to the "External" directory created in the previous step</li>
   <li><strong>Create a Windows Console C++ Project in VS 2022</strong></li>
  <li><strong>Move the .dll files to the directory that contains your classes:</strong> you cand find the .dll files in bin\Release\x64</li>
  <li><strong>Edit your Project Properties in your VS:</strong></li>
    <ol>
      <li><strong>C/C++ -> General -> Additional Include Directories:</strong> here add the include directories inside of glew and freeglut</li>
      <li><strong>Linker -> General -> Additional Library Directories:</strong> here add the lib\Release\x64 directories inside of glew and freeglut</li>
      <li><strong>C/C++ -> Input -> Additional Dependencies:</strong> here add the .dll files added at step 7, but with .lib extension, not .dll</li>
    </ol>
  </li>
</ol>

You will need to do steps from 3 to 8 for every project you start.


</br>
</br>
</br>
I hope that this repository helped you, for more details about me, you can access my website:  <a href="https://denisa-vasile.info/"> here </a>
