# C_CourseDesign_24a
Based on C, this course design includes 2 parts which are Task1_Micro_Management_System_Design and Task2_Digital_Personal_Seal.
***
# Step-by-Step Guide:

For the opening of the `Unrestricted_Guidance_2021.pdf` file, please refer to the commit description of the file.
Please unzip the compressed package `Fonts.7z` and use the txt files inside to replace all txt files with the same file names in the other folders.

## Task 1

Task 1 in this document refers to **Chapter 3, Task 2 (Design of a Small Management System Program)**. The contents in the folders *Demo_Grade_Management_System(Linked_List)* and *Demo_Grade_Management_System(Structure_Arrays)* are provided resources, and it is recommended to observe and learn from them first. The *Linked_List* version of the program can be viewed by directly examining the code in the `sms.c` file and attempting to run it. The *Structure_Arrays* version of the program needs to be opened in CodeBlocks by opening the `sms_main.cbp` file, then examining the files in the Sources and Headers sections on the left. Alternatively, you can directly view the `.c` and `.h` files in the folder.

Now, let's begin designing your own small management system program.

There are three options available:

1. Privacy Information Management System
2. Red Packet Management System
3. Single-Choice Question Standardized Examination System

The author has chosen option 3, the *Single-Choice Question Standardized Examination System*. The final implementation can be found in the `examoperation.c` file in the folder *Standardized_Examination_System_for_Single-Choice_Questions*. **This program is an original creation by the author and is licensed under Apache-2.0**.

Task 1 is relatively simple, and the implementation of each function is straightforward and easy to understand.

## Task 2

Task 2 in this document refers to **Chapter 4, Task 3 (Design of a Small Application Program)**, which consists of Q1 and Q2. First, let's introduce the functions of the various parts in the folder *Task2_Digital_Personal_Seal*:

The folder *Example_program_for_creating_BMP_images_(including_source_code)* contains the provided resources, with functionality corresponding to its name. The file `demo.c` is the source code for generating a BMP file.

The folder *Q1_Seal_From_txt_Demo* contains the provided resources, with functionality corresponding to its name. It is recommended to observe and learn from this first. The `mySeal.exe` file is an executable file, but it cannot be directly double-clicked to open. Use WIN+R to open the cmd prompt, navigate to the location of `mySeal.exe` using `cd`, press Enter, and follow the prompt. Then, input *mySeal 1.txt xxxx.bmp* to generate an image file named `xxxx.bmp` with the same pattern as `1.txt`. The `xxxx.bmp` in the input can be replaced with any other characters.

The folder *Q2_Seal_From_input_Demo* contains the provided resources, with functionality corresponding to its name. It is recommended to observe and learn from this first. The `mySeal.exe` file is an executable file, but it cannot be directly double-clicked to open. Use WIN+R to open the cmd prompt, navigate to the location of `mySeal.exe` using `cd`, press Enter, and follow the prompt. Then, input *mySeal LiShu56.txt xxxx.bmp*, followed by entering the four Chinese characters you want to appear. This will generate an image file named `xxxx.bmp` with the content of the four Chinese characters and the dot matrix style matching `LiShu56.txt`. The `xxxx.bmp` in the input can be replaced with other characters, and `LiShu56.txt` can be replaced with `XingKai56.txt`. (Note: The first character should appear at the top right, the second at the bottom right, the third at the top left, and the fourth at the bottom left.)

**The contents in the folder \*MySeals_Presentation\* are the original work of the author and are licensed under Apache-2.0**.

Seal1 implements Q1, with the source code located in the `atry.c` file. To use it, you can modify the Q1 demo method slightly to run `atry.exe`. Alternatively, open the `atry.cbp` file, go to *Project -> Set Program Arguments -> Program Arguments*, and input `xxxx.bmp`. This will generate an image file named `xxxx.bmp` with the same pattern as `fcp.txt`. You can replace `xxxx.bmp` with any other characters. On line 87 of the source code, you can replace `fcp.txt` with a text file of your own name. To create a custom text file for your name, refer to the `fcp.txt` file and create a new text file. Copy each character from `LiShu56.txt` or `XingKai56.txt` into the new text file, one by one. Note that the four characters should not be arranged in a single column but two characters per row. (If your name consists of only two characters, write it as "xx之印".)

Seal2 implements Q2, with the source code located in the `main.cpp` file. To use it, open the `seal2try001.cbp` file, go to *Project -> Set Program Arguments -> Program Arguments*, and input *xxxx.bmp LiShu56.txt* (the order cannot be switched). Run the program, and follow the prompt to enter any four Chinese characters. This will generate an image file named `xxxx.bmp` with the content of the four Chinese characters and the dot matrix style matching `LiShu56.txt`. You can replace `xxxx.bmp` with other characters, and `LiShu56.txt` can be replaced with `XingKai56.txt`.

**Program Principle:**

First, carefully compare the source code of Q1 with the `demo.c` file. By combining the source code with the comments, the specific principles such as coloring the border and dot matrix characters can be understood.

Then, compare Q2 with Q1 to understand how to extract the dot matrix characters of the required Chinese characters from the font files, accurately offset them, place them in arrays, and arrange them according to the seal order in the BMP image.
