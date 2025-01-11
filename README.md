
# Data Structure Assignment - Stack & Queue Implementation

## Overview

This assignment focuses on using stack and queue data structures to handle various tasks such as file parsing, error detection, Least Recently Used (LRU) caching, and image processing using OpenCV. The goal is to implement efficient parsing, error handling, file management, and image object detection.

## Requirements

1. **C++ Compiler**: Ensure that you have a C++ compiler installed (e.g., GCC, Clang).
2. **OpenCV**: For image processing, OpenCV is required. Install it using the following commands:
   - **Linux**:
     ```bash
     sudo apt-get update
     sudo apt-get install libopencv-dev
     ```

3. **Test Files**: Place your text files in the `Test_files` folder for parsing and processing.
4. **Images**: Place images in the `Images` folder to be processed and detected.

## Project Structure

```
/Assignment2
├── Test_files            # Contains text files for parsing
├── Output_files          # Contains output files after processing
├── Images                # Contains images to be processed
├── Sol
│   ├── main.cpp            # Main entry point
│   ├── DEQueue.cpp         # Implementation of DEQueue Datastructure   
│   ├── FileRead_Stack.cpp  # Implementation of Stack which is used for reading files.
│   ├── Notations.h         # Header file for functions of prefix, postfix notations etc. 
│   ├── Parsing.h           # Logic for Parsing HTML tags
│   ├── Queue.h             # Implementation of Queue data structure
│   ├── Stack.h             # Implementation of stack data structure
│   ├── tag_functions.h     # Implementation of logic of the respective tags which has been used
├── README.md               # Project Documentation (Project.pdf is also present for requirements)
├── Code Files              # Build configuration
```

## Instructions to Run

### Step 1: Setup the Environment
Make sure you have the necessary dependencies installed. Specifically, install OpenCV for image processing:

1. Install OpenCV and Set Environment Variables
Follow the steps in this YouTube tutorial to:
   1.ownload and install OpenCV.
   2.Set environment variables for OpenCV to ensure compatibility with Visual Studio.

2. Configure Project Paths
After setting up OpenCV, configure the paths in the Visual Studio project files to ensure the project compiles and runs successfully. Update the include directories and linker settings as needed.

### Step 2: Run the Code using Visual Studio
This will process all the text files in the `Test_files` folder, handle the LRU cache, process images, and save outputs in the `Output_files` folder.

### Step 4: Review the Output
The program will generate outputs for file parsing, expression handling, image processing, and LRU cache results. You can review the output files located in the `Output_files` directory.

## Task Breakdown

1. **File Parsing**:
   - Handles tags such as start, head, paragraph, post_exp, pre_exp, etc.
   - Processes expressions, handles error detection, and formats outputs in postfix, prefix, and evaluated formats.
   - Detects syntax errors, missing/extra tags, and malformed expressions.

2. **Error Detection**:
   - Identifies and reports syntax errors and invalid expressions.

3. **Least Recently Used (LRU) Cache**:
   - Manages file access priority using a queue with a fixed size of 4.
   - Tracks cache hits and faults, providing a summary in the output.

4. **Image Processing**:
   - Detects objects in images using OpenCV.
   - Processes images row-wise and column-wise, separating objects based on white pixel regions.

## Output Example

```
		First File.
	
		The file getting processed and the converted postfix notations are abc*+ and INVALID EXPRESSION.
		One more statement to test your coding skills to handle the character arrya without using any builtin funciton, 
		so show this expression in to prefix form -*a/b^+cdfg. 
		The skill test doesn't stop there,
		you have to evaluate on more statement to prove your  skills on basic stack working. 
		Evalaution result of provided strings are (a+(b*c)).
	 
		So,you said you enjoyed the previous assignment and learned much and more :). Now, tell me the about the number of galxies in the picture.		
		Total galxies in picture are 3. 
	
		this is just check your stack handling skills.  so i hope you will pass  this test also
		so keep going . So, now I am  tried of this thing.  I think that's enough.
	
No dangling tag remains

*******************************************END******************************************

			 	 	 2nd File.
	
		The file getting processed and the converted postfix notations are abc*+ and INVALID EXPRESSION.
		One more statement to test your coding skills to handle the character arrya without using any builtin funciton, 
		so show this expression in to prefix form -*a/b^+cdfg. 
		The skill test doesn't stop there,
		you have to evaluate on more statement to prove your  skills on basic stack working. 
		Evalaution result of provided strings are (a+(b*c))  SYNTAX ERROR 
		So,you said you enjoyed the previous assignment and learned much and more :). Now, tell me the about the number of galxies in the picture.		
		Total galxies in picture are 3 SYNTAX ERROR
	
...
