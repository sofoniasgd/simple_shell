# Simple Shell

A Unix command-line interpreter

## Table of Contents
- [Overview](#overview)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
  - [Interactive Mode](#interactive-mode)
  - [Non-Interactive Mode](#non-interactive-mode)
- [Features](#features)
- [Contributors](#contributors)
- [CopyRight](#CopyRight)

## Overview

This Simple Shell project is a Unix command-line interpreter developed as part of the ALX Software Engineering program. It is designed to challenge your understanding of various programming and Unix concepts, including process creation, environment variables, and error handling.

## Getting Started

### Prerequisites

Before you begin, ensure you have met the following requirements:
- **Operating System:** Ubuntu 20.04 LTS
- **Compiler:** GCC (GNU Compiler Collection)

### Installation

To get started with the Simple Shell, follow these steps:

1. Clone the project repository to your local machine:

    ```
    git clone https://github.com/bini34/simple_shell.git
    ```

2. Compile the shell using GCC:

    ```
    gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
    ```

3. Run the shell:

    ```
    ./hsh
    ```

## Usage

### Interactive Mode

In interactive mode, the shell waits for your input and executes commands as you enter them. Here's an example:
$ ./hsh
$ ls
file1.txt file2.txt
$ echo "Hello, World!"
Hello, World!
$ exit

### Non-Interactive Mode

In non-interactive mode, you can provide a script file containing commands to execute. Use the following syntax:
$ echo "ls\necho 'Hello, World!'" | ./hsh

## Features

- Basic shell commands like `ls`, `echo`, and `exit` are supported.
- Command lines with arguments are handled.
- The `PATH` variable is used to find executable programs.
- Error handling for invalid commands and input.

## Contributors

This project was developed by the following contributors:
- Biniyam BEYENE
- Sofonias Dubale

## CopyRight

Copyright (C) 2023  by [**Biniyam Ambachew**](https://github.com/bini34) and [**Sofonias Dubale**](https://github.com/sofoniasgd)<br>
All rights reserved



