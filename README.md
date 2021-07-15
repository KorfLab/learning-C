learning-C
==========

An introduction to programming in C using example programs. It is assumed you've done some programming in Python, Perl, Javascript, or some other modern programming language.

## Contents ##

+ Setup
+ Hello World
+ Comments
+ Variables
+ Strings
+ Conditionals
+ Structs
+ Functions
+ Arrays
+ Pointers
+ File I/O
+ CLI
+ Headers
+ Libraries
+ Make


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

## Strings ##

Copy `templates/strings.c` to your directory. Read the text below, then compile and run the program. Then come back and read this again.

Strings are arrays of characters. We will deal with arrays more later, but for now just accept that `char s[5]` creates enough room for a string with 4 letters and one string terminator.

The most dangerous thing about strings, and arrays in general is that there's absolutely nothing stopping you from doing this:

	char s[5];
	s[50] = 'a';

You have asked for 5 bytes to hold a string, s. However, the array syntax allows you to read or write memory well beyond the original bounds. This can cause catastrophic errors if you disturb other parts of memory. If this doesn't scare the shit out of you, you don't understand the problem.

Depending on what version of the gcc compiler you used, you may have seen warning messages. One of those warnings may be because the code implicitly converts one type of integer into another.

	printf("len:%d size:%d\n", strlen(s2), sizeof(s2));

The `strlen()` and `sizeof()` functions return unsigned integers while the `printf()` format specification `%d` expects an integer. In order to silence the warnings, you can _cast_ one type of variable into the other or use `%lu` in `printf()`.

	printf("len:%d size:%d\n", (int)strlen(s2), (int)sizeof(s2));
	printf("len:%lu size:%lu\n", strlen(s2), sizeof(s2));

Ideally, your code shoudln't produce any warnings ever. However, not all compilers generate the same warnings. So sometimes you have to compile on multiple platforms to find your warnings and errors. Having to compile your code everywhere is a pain. This was largely solved by Java, which you only had to compile once. However, since evey Java interpreter was different, it spawned the phrase "compile once, debug everywhere". It amounts to the same thing: programming in C or Java requires simultaneously developing on multiple platforms.

## Conditionals ##

Copy `templates/conditionals.c` to your directory and try that out. Most of it should look pretty familiar to you. You may not have seen a `case` or `do` or `goto` statement before, but they aren't complicated.

To get your fingers used to doing loops and conditionals in C, write the ubiquitous `fizzbuzz` program (output the numbers from 1 to 100, but if the number is divisible by 3 write fizz, divisible by 5 write buzz, divisible by both 3 and 5 fizzbuzz).

## Structs ##

Structures, or 'structs' for short are collections of variables all stored together. Sometimes structs are called objects. The basic form of a struct is as follows:

	struct person {
		char name[32];
		int age;	
	};

That is, each property of a struct has an identifier (e.g. name, age) and a variable type (e.g. char array, integer). To get to a specific property of a struct, you use dot syntax as in `variable.name` and `variable.age`. Later, we will use pointers to structs which will have a similar but distinct representation: `variable->name` and `variable->age`.

## Arrays ##

Arrays are linear collections of variables all of the same type. In C, arrays have a fixed size when they are created. As such, there are no functions to append or push data onto them. They cannot grow and they don't know how many elements you have decided to use. You have to manage their size and keep track of how much of the array is currently in use.

As we saw earlier with strings (which are arrays of type char terminated with `\0`), it is possible to accidentally access arrays beyond their final index. This is probably the most common type of catastrophic error.

## Functions ##

This is unfinished...

First, a word about scope. The scope of a variable is where it is visible. Most modern languages don't use global scope very much. However, in C, all of the functions are generally in global scope. That means you can't have two different functions with the same name coming from different libraries. You also can't have global variables with the same name.

In many modern languages, each package has its own namespace. If you want to define `printf()` in a specific namespace, there's nothing preventing you from doing that as `mypackage.printf()`. However, in C, you cannot do this. Every function has to have a unique name. For this reason, developers often put a unique-ish prefix on the front of their functions. For example, I might use my initials to make `ik_printf()`. Another way to prevent your global variables from colliding with other global variables and functions is to declare them as `static`.


In C, functions always have exactly one return value. For example, if you have a function called `sum()` that takes two numbers, you would expect that it would return the sum of those numbers. You would also expect that it didn't change those numbers in any way. Put another way, functions do this:

+ have a single return value
+ have no side-effects (don't change their input values)




What if you want a function to return multiple values? For example, let's say you have a `stats()` function that should return the min, max, mean, median, etc. There's more than one way to accomplish this. One way is to send in the memory locations of the variables you want to set.


## Pointers ##

Pointers to simple types
malloc() and free()
Pointers to structs
Stack vs. heap
Heap arrays

## File I/O ##

## CLI ##

## Headers ##

## Libraries ##

## Make ##


