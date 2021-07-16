C for Python programmers
========================

Python is a great language for 95% of our programming needs. Sometimes it's not fast enough, and for those times there is C. This repo chronicles the "adventures in C" of the Korf Lab in the Summer of 2021.

## Contents ##

+ Setup
+ Hello World
+ Comments
+ Variables
+ Strings
+ Conditionals
+ Structs
+ Arrays
+ Functions
+ The Global Namespace
+ Memory
+ Garbage Collection
+ Pointers
+ File I/O
+ CLI
+ Headers
+ Make
+ Libraries
+ Pseudo-OOP

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

Some big differences from Python include the following:

+ Every statement ends in a semicolon
+ Curly brackets define scope rather than indentation
+ There are weird things like #include statements

Time to compile the program.

	gcc hello_world.c

This creates a file called `a.out`.

Run the program.

	./a.out

You can name your programs with the `-o` option.

	gcc hello_world.c -o greeting
	./greeting

Or you can just use `a.out` for these demo programs. The file will be ignored by `git` because it's in the `.gitignore` file. Here's how I would go about compiling and running the demo programs (this only runs the program if the compiler returns 0 -- success).

	gcc hello_world.c && ./a.out

## Comments ##

There are 2 styles of comments in C, multi-line comments, and single-line comments.

	/*
		A multi-line comment begins with slash-star and ends with star-slash
		This is useful for commenting-out large blocks of code
		So, use this much as you would triple-quotes in Python
	*/

In the classic version of C, the only kind of comments were multi-line. Of course, you could put them on one line. But now, most C-compilers also recognize single-line comments, which were introduced in C++ (maybe).

	/* single-line comment the old way */
	// single-line comment the new way

The `#` symbol is *NOT* a comment. Lines that begin with a `#` sign are part of the pre-processor directives.

Add a few comments to your previous `hello_world.c` program in both styles and make sure your program compiles and runs properly.

## Variables ##

In C, all variables are strictly typed. You cannot create a variable and decide later if it will contain an integer, floating point number, or string.

Copy the `variables.c` program from `templates` to your directory. Compile and run that. Then add your own variables and your own `printf()` statements.

Note that this program added a couple new things. First off there was the `#include <math.h>` that is used to bring in a definition of PI. Also, the `printf()` statement has a few new ways of being used.

Possibly the most important part of this program is to note that variables a, b, and c were never given any value. There is no `None` type in C. When the program runs, all variables have a value. Varibles in C are just raw memory locations. When you declare a variable, you're getting whatever cruft was left in memory at that location from some earlier point in time. Each time you run your program, you may have a different value!

So what should you do about variables with unknown contents? Should you set all of your variables equal to zero at the start of your program? Absolutely not. A program with random behavior is obviously a buggy program. However, if you set the variables to zero, it's probably still a buggy program but you can't tell because it behaves consistently.

## Strings ##

Copy `templates/strings.c` to your directory. Read the text below, then compile and run the program. Then come back and read this again.

Strings are arrays of characters. We will deal with arrays more later, but for now just accept that `char s[5]` creates enough room for a string with 4 letters and one string terminator.

The most dangerous thing about strings, and arrays in general is that there's absolutely nothing stopping you from doing this:

	char s[5];
	s[50] = 'a';

You have asked for 5 bytes to hold a string, s. However, the array syntax allows you to read or write memory well beyond the original bounds. This can cause catastrophic errors if you disturb other parts of memory. If this doesn't scare the shit out of you, you don't understand the problem.

Depending on what version of the gcc compiler you used, you may have seen warning messages when you compiled `strings.c`. One of those warnings may be because the code implicitly converts one type of integer into another.

	printf("len:%d size:%d\n", strlen(s2), sizeof(s2));

The `strlen()` and `sizeof()` functions return unsigned integers while the `printf()` format specification `%d` expects an integer. In order to silence the warnings, you can _cast_ one type of variable into the other or use `%lu` in `printf()`.

	printf("len:%d size:%d\n", (int)strlen(s2), (int)sizeof(s2));
	printf("len:%lu size:%lu\n", strlen(s2), sizeof(s2));

Ideally, your code shouldn't produce any warnings, ever. However, not all compilers generate the same warnings. So sometimes you have to compile on multiple platforms to find your warnings and errors. Having to compile your code everywhere is a pain. This was largely solved by Java, which you only had to compile once. However, since evey Java interpreter was different, it spawned the phrase "compile once, debug everywhere". It amounts to the same thing: developing on multiple platforms makes software more robust. I am currently using Mac OS, Debian, Linux Mint, and Haiku.

Later, when we work with makefiles, we'll use compiler options that turn on as many warnings as possible to make our code as squeaky-clean as possible.

## Conditionals ##

Copy `templates/conditionals.c` to your directory and try that out. Most of it should look pretty familiar to you. Python doesn't have `case`, `do`, or `goto` statements, but they aren't complicated.

To get your fingers used to doing loops and conditionals in C, write the ubiquitous `fizzbuzz` program (output the numbers from 1 to 100, but if the number is divisible by 3 write fizz, divisible by 5 write buzz, divisible by both 3 and 5 fizzbuzz).

## Structs ##

Structures, or 'structs' for short are collections of variables all stored together. Sometimes structs are called objects. The basic form of a struct is as follows:

	struct person {
		char name[32];
		int age;	
	};

That is, each property of a struct has an identifier (e.g. name, age) and a variable type (e.g. char array, integer). To get to a specific property of a struct, you use dot syntax as in `variable.name` and `variable.age`. This all looks like object-oriented programming in Python. However, most of the time the objects don't bind to functions. So you will see `obj.name` but you will very rarely see `obj.method()` (although I do this on occasion).

Later, we will use pointers to structs which uses the arrow representation: `variable->name` and `variable->age`. If you are a Perl programmer, this may give you a warm, fuzzy feeling.

## Arrays ##

In Python, lists can contain variables of mixed types, but not in C. All of the elements of a C array must be of the same type. Not only that, but when you create an array, you must say exactly how large you want it to be. As such, there is no `append()` function. C arrays cannot grow and they don't know how many elements you have decided to use. You have to manage their size and keep track of how much of the array is currently in use.

As we saw earlier with strings (which are arrays of type char terminated with `\0`), it is possible to accidentally access arrays beyond their final index. This is probably the most common type of catastrophic error.

## Functions ##

In Python, functions can return multiple values, but in C every function has at most one return value. For example, the `main()` function returns an integer.

	int main() {...}

If you don't want a function to return anything, you can have it return void.

	void function() {...}

So what happens if you want a function to return multiple values? For example, let's say you have a `stats()` function that should return the min, max, mean, median, etc. How do you get the individual values? Simple: return a struct.

	s = stats(values);
	s.max
	s.mean

There is another way, which is to send in memory locations to the function and have the function fill the variables. This violates my "functions don't have side-effects" rule. Passing memory addresses to functions is pure evil (even though it shows up in most textbooks).

## The Global Namespace ##

Before a C program is compiled, it goes through a preprocessor. This is its own mini language. You've already seen one preprocessor command before.

	#include <stdio.h>

Statemets that begin with a # sign are read by the preprocessor. An `#include` statement says "open up the file and copy its entire contents here". What if different files define the same function name? In Python, each file has its own namespace. For example, you might do `some_library.sum()`, and this would not conflict with any other file that also defined a `sum()` function. In C, there is no dot syntax that divides the namespace. In C, all of the functions are in the same global namespace!

To prevent namespace collisions, each function needs a completely unique name. Consequently develoeprs often prefix their functions with their initials or some other identifying token. For example, if I wanted to make my own version of `printf()`, I might call it `ik_printf()` or if this was part of a larger biological sequences library I might call it `bs_printf()`.

Variables can also exist in the global namespace. But just like functions, they cannot have the same names as other variables (or functions for that matter). By convention, global variables should start with a capital letter. If you want to make a variable a constant, use the `const` keyword. By convention, it should also be in all capitals.

	int GlobalVariable = 3;        // can be changed
	const int GLOBAL_CONSTANT = 5; // cannot be changed

	int main () {
		int thing; // lowercase as all local variables should be	
	}

If you're worried about polluting the global namespace with your variables and functions (and you should be), you can make these private to a specific file with the keywords `static`.

	static int Mine; // variable private to the file
	static int also_mine() {} // function private to the file
	int main() ...

The variable `Mine` and function `also_mine()` look like they are part of the global namespace, but they can't be accessed by code outside the file they are defined in (which doesn't have to be the file with `main()`).

---

One common use of the the preprocessor is to define macros that substitute text throughout a file. For example, let's say you want to declare an array with 100 elements. Later you decide that it should be 200. Do you want to go to all places in your code that had 100 and change them to 200? No, instead you can use a macro.

	#define ARRAYSIZE 100

	int array[ARRAYSIZE]
	for (int i = 0; i < ARRAYSIZE; i++) ...

---

Oh yeah, let's put everything we know so far in a program. Go get `global.c` from the `templates` directory and play with that.


## Memory ##

Everything up to now should have been mostly familiar. But we're about to go off the chart and there be dragons out there...

---

Consider this simple function. It doesn't take any arguments and it doesn't return any values. However, each time it is called, it creates an array of size 1 kb.

	void stack(void) {
		char mme[1024];
	}

What happens to that memory after the function is called? Does it hang around? Or does it disappear. You can imagine that if it hangs around, then a program like the following would eventually use up all the memory in your computer.

	int main() {
		while (1) stack();
	}

Grab `templates/memory.c` and try it out. Make sure you have `top` or some other process manager running at the same time. You'll see that the memory usage of your program will not increase over time. To kill the program, use Control-C.

All of the variables we've seen so far are allocated from the _stack_. Memory is created when you ask for it, and when the program execution leaves the function, the memory is returned. The stack is a first-in last-out queue. Because stack memory is always recycled, there is no way for stack memory to be returned from a function. You cannot create a random DNA sequence from stack memory and then return it to the `main()` function. That memory is gone as soon as you leave the function.

There is another part of memory called the _heap_ and it is not a first-in last-out queue. It works like the filesystem on your hard disk. When you create files, they take up room permanently until you personally destory them. This next function allocates memory from the heap.

	void heap(void) {
		char *mem = malloc(sizeof(1000));
	}

What do you think will happen if you do the following?

	int main() {
		while (1) heap();
	}

Switch the comments around and try it and find out. But be ready with the ^C (that's how people often write Control-C).

So how do you get rid of the memory? By manually releasing it with the `free()` function. If you don't `free()` memory, your computer will run out of RAM. If you `free()` the wrong piece of memory, your program will crash (or worse). Switch the comments around again and try the last piece of code in `memory.c`.

## Garbage Collection ##

How does Python (and many other modern languages) do garbage collection?

## Pointers ##

Pointers to scalars
malloc() and free()
Stack vs. heap
Pointers as arrays
Pointers to structs

## File I/O ##

## CLI ##

## Headers ##

## Make ##

## Libraries ##

## Pseudo-OOP ##

