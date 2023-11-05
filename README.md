# get_next_line_42

Nobody wants to read a file in a while-loop reading it in arbitrary lenghts!

## Description

This project required of us to write a function `get_next_line()` that returns the line of a file one by one with every call. 
It taught about me memory management, buffering, static variables and becoming more comfortable with the system call `read()` and file descriptors.

## Table of Contents

- [get_next_line](#project-title)
- [Description](#description)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)

## Getting Started

### Prerequisites

You will need `GNU Make version 3.81` or higher ( https://www.gnu.org/software/make/ ).
To compile you will also need a gcc compiler. At school we use `clang version 11.0.0`
( https://gcc.gnu.org/install/download.html )

### Installation

Open a terminal window and `cd` into a directory of your choice. Clone the repo via `git clone <link to remote repo>` 
to your machine and execute `cd get_next_line && make`.
  
## Usage
  
The library is compiled into libft.a and can be included in your projects by including the path to the 'libft.h'
file and linking the library to your project during compilation with -L[path to libft directory]:

```
{
### GNU MAKEFILE ###

NAME = your_project
SRC = [your source files]
INC = [your header files]

$(NAME): $(SRC) $(INC)
    gcc -I$(INC) $< -o $@ -L[path to libft directory] -lft
}
```
