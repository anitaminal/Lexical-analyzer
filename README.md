# Lexical-analyzer
To design a lexical analyzer that identifies the keywords, operators, identifiers, floating point, characters, and strings that are written as part of the source program

Project Overview:
A Lexical Analyzer is a component of a compiler that reads source code and identifies individual tokens such as keywords, identifiers, operators, literals, and special symbols.
This project implements a lexical analyzer using the C programming language. It reads a source file provided through command-line arguments, processes the input character by character, and identifies tokens according to their types.

Objectives
* Understand the fundamentals of lexical analysis in compiler design.
* Read and validate a source file using command-line arguments.
* Process the source code character by character.
* Form tokens from the input stream.
* Identify and classify supported token types.
  
Pre-requisite:
* Basic knowledge of compiler design
* File I/O
* String Handling
* Pointers, character classification functions

Steps:
1.  Read the file from the command line arguments and validate the file.
2.  Open the source file and read its contents character by character.
3.  Form tokens based on lexical conditions.
4. Identify and classify supported keywords, identifiers, literals, operators,and special symbols.
  
Learnings and challenges:
  * Understood how to form tokens from a stream of characters.
  * Practiced string handling and character classification using functions such as isalpha(), isalnum(), and isdigit().
  * One of the main challenges was forming exact tokens from a continuous stream of characters.
  * One of the main challenges was forming exact tokens from a continuous stream of characters. This was addressed by implementing conditions to determine token boundaries and classify the input.

Compilation and Execution:
Compile all the source file
      gcc *.c 
Run the program by passing a C source file as a command line argument:
      ./a.out test.c

Author:
Anita Minal A
Developed as part of embedded software training to strengthen C programming skills and understand compiler fundamentals.
