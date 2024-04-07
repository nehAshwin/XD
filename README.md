# XD

## Project Overview
In this project, I have built my own version of the basic program functionality of the Unix system xxd. The challenge with this project is that I did not use functions such as fopen() or fread(), which do any buffering for me. Instead, I opted for open() and read(), functions that are "System Calls" and engage directly with the operating system. This approach presents unique challenges, such as managing file descriptors rather than file stream pointers. Throughout this project, I tackled these challenges through research and implementation.

### XXD
While xxd produces a hexadecimal representation of binary files and can reverse the process, XD focuses solely on generating the hexadecimal representation without the ability to reverse it.

## Data Structures and Programming Concepts
This project has provided valuable insights into reading files using C programming, implementing buffers, managing throttled input, and converting binary to hexadecimal within a program.
