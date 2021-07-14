learning-C
==========

An introduction to programming in C using example programs.

## Contents ##

+ Setup
+ Hello World
+ Comments
+ Variables
+ Strings
+ Conditionals
+ Loops
+ Arrays
+ Functions
+ File I/O
+ CLI
+ Make
+ Libraries

## Setup ##

You will need `git`, `gcc`, and `make` on your computer. If these are not installed, you will have to install them yourself.

1. Clone this repository to your computer. `git clone https://github.com/KorfLab/learning-C`
2. Make a directory for yourself. Do all of your work inside that directory.

## Hello World ##

Open your favorite editor and create the following program: `hello_world.c`. You can find this program in the `templates` directory of the repository in case you would rather copy than type.

	#include <stdio.h>
	int main() {
		printf("hello world\n");
	}

Compile the program.

	gcc hello_world.c

This creates a file called `a.out`.

Run the program.

	./a.out

You can name your programs with the `-o` option.

	gcc hello_world.c -o greeting
	./greeting

## Comments ##

There are 2 styles of comments in C, multi-line comments, and single-line comments.

	/*
		a multi-line comment begins with slash-star
		and ends with star-slash
	*/

In the classic version of C, the only kind of comments were multi-line. Of course, you could put them on one line. But now, most C-compilers also recognize single-line comments, which were introduced in C++.

	/* single-line comment the old way */
	// single-line comment the new way

The `#` symbol is *NOT* a comment. Lines that begin with a `#` sign are part of the pre-processor directives.

Add a few comments to your previous `hello_world.c` program in both styles and make sure your program compiles and runs properly.

## Variables ##

In C, all variables are strictly typed. You cannot create a variable and decide later if it will contain an integer, floating point number, or string.

Copy the `variables.c` program from `templates` to your directory. Compile and run that. Then add your own variables and your own `printf()` statements.

Note that this program added a couple new things. First off there was the `#include <math.h>` that is used to bring in definitions of PI. Also, the `printf()` statement has a few new ways of being used.

Possibly the most important part of this program is to note that variables a, b, and c were never given any value. And yet when the program runs, they have a value. Varibles in C are just raw memory locations. When you declare a variable, you're getting whatever cruft was left in memory at that location. Each time you run your program, you may have a different value.

Try declaring some floating point variables and then print their values. You might be surprised at the results.

So what should you do about variables with unknown contents? Should you set all of your variables equal to zero at the start of your program? Absolutely not. A program with random behavior is obviously a buggy program. However, if you set the variables to zero, it's probably still a buggy program but you can't tell because it doesn't have random behavior.


