# Digital Image Processing

In this repository you can find all homeworks, projects and resources regarding my studies at the **University Transilvania of Brasov** (**Bachelor in Computer Science**), years: 2020-2023.<br>
You may use these materials as long as you mention the source and the author. <br>
Copyright - [DenisaXXIV](https://github.com/DenisaXXIV)

## [I. Mirror Image](https://github.com/DenisaXXIV/FMI-UniTBv/tree/master/Year_2/Semester_II/PID%20-%20Digital%20Image%20Processing/Mirror%20Image)
Mirrors the source image to the vertical axis.

<img src="https://github.com/DenisaXXIV/FMI-UniTBv/blob/master/Year_2/Semester_II/PID%20-%20Digital%20Image%20Processing/util/Mirror.png" height="400px">

## [II. 1-Threshold Binarization](https://github.com/DenisaXXIV/FMI-UniTBv/tree/master/Year_2/Semester_II/PID%20-%20Digital%20Image%20Processing/1-threshold%20binarization)
1-threshold binarization: a dialog box is opened, a T-binarization threshold is inserted (with values in the range 10 -154). The resulting image will be a 2-tone image (black and white) in which, each pixel P, which in the source image with T <= P will turn white and each pixel, which does not satisfy the relationship will turn black.

<img src="https://github.com/DenisaXXIV/FMI-UniTBv/blob/master/Year_2/Semester_II/PID%20-%20Digital%20Image%20Processing/util/Binarized.png" height="400px">

## [III. Directional filtering with Sobel filter](https://github.com/DenisaXXIV/FMI-UniTBv/tree/master/Year_2/Semester_II/PID%20-%20Digital%20Image%20Processing/Directional%20filtering%20with%20Sobel%20filter)
- in the Filters menu add a menu option - Sobel directional filter
- read the T threshold from a dialog box
- apply the two Sobel Sx and Sy filters on the source image
- if for a pixel (x, y), Degree(x, y) <T, then in the image result the pixel will be black. Otherwise the pixel (x, y) is colored in the resulting image depending on the color gradient angle from 127 to 255 for angles from 0 ° to 360 °

<img src="https://github.com/DenisaXXIV/FMI-UniTBv/blob/master/Year_2/Semester_II/PID%20-%20Digital%20Image%20Processing/util/Sobel.png" height="400px">

## [IV. Rotate images using bicubic interpolation](https://github.com/DenisaXXIV/FMI-UniTBv/tree/master/Year_2/Semester_II/PID%20-%20Digital%20Image%20Processing/Rotate%20images%20using%20bicubic%20interpolation)
- add a menu option - Rotation
- read the rotation angle (in degrees) from a dialog box (Obs. Must be transformed into radians).
- apply the rotation operation starting from the resulting image to the source image, using bicubic interpolation

<img src="https://github.com/DenisaXXIV/FMI-UniTBv/blob/master/Year_2/Semester_II/PID%20-%20Digital%20Image%20Processing/util/rotation.png" height="400px">

I hope that this repository helped you, for more details about me, you can access my website: [here](https://denisa-vasile.info/).


