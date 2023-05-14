<br/>
<p align="center">
  <a href="https://github.com/abdelemjidessaid/simple_shell"></a>

  <h1 align="center">Simple Shell</h1>

  <p align="center">
    Simple shell similar to Unix shell.
    <br/>
    <br/>
    <a href="https://github.com/abdelemjidessaid/simple_shell"><strong>Explore the docs »</strong></a>
    <br/>
    <br/>
    <a href="https://github.com/abdelemjidessaid/simple_shell">View Demo</a>
    .
    <a href="https://github.com/abdelemjidessaid/simple_shell/issues">Report Bug</a>
    .
    <a href="https://github.com/abdelemjidessaid/simple_shell/issues">Request Feature</a>
  </p>
</p>

![Downloads](https://img.shields.io/github/downloads/abdelemjidessaid/simple_shell/total) ![Contributors](https://img.shields.io/github/contributors/abdelemjidessaid/simple_shell?color=dark-green) ![Forks](https://img.shields.io/github/forks/abdelemjidessaid/simple_shell?style=social) ![Stargazers](https://img.shields.io/github/stars/abdelemjidessaid/simple_shell?style=social) ![Issues](https://img.shields.io/github/issues/abdelemjidessaid/simple_shell) ![License](https://img.shields.io/github/license/abdelemjidessaid/simple_shell) 

## Table Of Contents

* [About the Project](#about-the-project)
* [Built With](#built-with)
* [Getting Started](#getting-started)
  * [Prerequisites](#prerequisites)
  * [Installation](#installation)
* [Usage](#usage)
* [Authors](#authors)
* [Files description](#files-description)

## About The Project

* This is a Simple Shell project, one of the most anticipated projects in our programming course. The project will challenge us in many ways and will require us to apply everything we have learned so far, including the basics of programming, C language, thinking like an engineer, group work, and learning how to learn.

* The goal of this project is to develop a simple command-line interface (CLI) shell that can execute commands entered by the user. The shell should be able to handle basic commands such as ls, cd, pwd, cp, mv, rm, and others.

* We will be using C language to develop the shell and will be working closely together as a team. Collaborating on this project will help us to improve our coding skills and learn how to work effectively with others on a software development project.

* We are excited to take on this challenge and look forward to learning and growing together as we develop our Simple Shell.

## Built With

This project built with `C programming language`.

## Getting Started

This is an example of how you may give instructions on setting up your project locally.
To get a local copy up and running follow these simple example steps.

## Prerequisites

First you need to install the `gcc` compiler in you machine.

To install the GCC compiler on Ubuntu, you can follow these steps:

* Open the terminal on your Ubuntu system by pressing Ctrl+Alt+T.
* Type the following command to update the package list:
```
sudo apt update
```
 * Once the package list is updated, type the following command to install GCC:
```
sudo apt install gcc
```
* This will install the GCC compiler on your Ubuntu system. You can verify the installation by checking the version of GCC installed on your system using the following command:
```
gcc --version
```


## Installation

1. Clone the repository:

```
git clone git@github.com:abdelemjidessaid/simple_shell.git
```

2. Open the repository dir:

```
cd simple_shell
```

3. Compile the project files:

```
gcc *.c -o run
```

4. Run the program:

```
./run
```

5. Enjoy.


## Authors

* **Abdelemjid Essaid & Khaoula Berrah** - *ALX Software Enginnering Students* - [Abdelemjid Essaid & Khaoula Berrah](https://github.com/abdelemjidessaid)


## Files description:

>
> - `AUTHORS` this file contains Emails of collaborators.
>
> - `simple_shell.c` this file contains __main__ function, which is the entry of program.
>
> - `header_file.h` this file relates with all project files, and contains __function prototypes__, __other header files__, __macros__ and __structs__.
>
> - `execution.c` this file contains the __functions__ which runs the programs as __ls, cd...__
>
> - `handle_environment.c` this file contains the __functions__ which handle the paths of environment.
>
> - `counters.c` this file contains the __functions__ that counts something.
>
> - `line_parser.c` this file contains the __function__ that split the line entered by the user as commands to be run, and handles its uses.
>
> - `memory.c` this file contains the __functions__ which had deal with memory as __malloc & free__.
>
> - `string_lib.c & string_lib_2.c` these files contains the __functions__ that had deal with strings.
>
