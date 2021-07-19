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
+ Pseudo-OOP
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

Switch the comments around and try it to find out. But be ready with the ^C (that's how people often write Control-C).

So how do you get rid of the memory? By manually releasing it with the `free()` function. If you don't `free()` memory, your computer will run out of RAM. If you `free()` the wrong piece of memory, your program will crash (or worse). Switch the comments around again and try the last piece of code in `memory.c`.

## Garbage Collection ##

How does Python (and many other modern languages) manage memory? That is, how does Python make sure that some variables get cleaned up and others do not? Consider the following two Python functions.

	def f1:
		a = "hello";
	
	def f2:
		a = "hello";
		return "hello";

Now let's imagine running these in an infinte loop.

	while True:
		f1()

Does `f1()` cause your computer to run out of memory? No.

	while True:
		thing = f2()

Does `f2()` cause your computer to run out of memory? Also no. And yet memory did get returned and stuck into `thing`.

What happened, invisibly, is that each time through the `while` loop, `thing` goes out of scope, and the memory that was originally created in `f2()` now gets garbage collected. In Python, every piece of memory has a "reference count". In `f1()`, when `a` gets associated with the memory of `hello`, the memory has a reference count of 1. When execution leaves the function, the count goes to 0 and the memory is freed. In `f2()` the return statement increases the reference count by 1. So even though `a` goes out of scope, reducing the reference count by 1, the memory still has a reference count of 1. When `thing` finally goes out of scope, the reference count goes to zero and the memory is freed. Does this mean its impossible to have a memory leak in Python. No. Here's how to make a Python program use all your memory.

	stuff = []
	while True:
		stuff.append(f2())
	
Each time `f2()` is called, the memory gets put on an array. The memory won't get freed until the entire array goes out of scope.

## Pointers ##

We are now at the point of our adventures in C where some of our intrepid group will want to run screaming. Pointers are scary to some people. To declare a variable as a pointer, you prepend it with a `*`.

	char c = 'A'; // a variable containing 1 byte - the letter A
	char *p;      // a pointer to a character

A pointer is a variable that can hold a memory address. How big is a memory address? It depends if you are using a 32-bit or 64-bit OS. So, either 4 or 8 bytes.

	printf("%lu\n", sizeof(p)); // probably 8

Let's make sure we get this straight in our heads. The variable takes up 1 byte but if you want to find its memory address, that takes 8 bytes.

OK, so here's exactly where the fun begins. The ampersand `&` gives the memory address of a variable. Not the contents of the variable, but the address.

	p = &c; // p now contains the memory address of c
	printf("contents: %c, address: %lu\n", c, p);

A pointer lets you access the memory directly, without going through the variable's name.

	*p = 'B';
	printf("contents: %c, address: %lu\n", c, p);

In C, when you pass a variable to a function, it makes a copy of the variable. This is known as pass by value. As a result, the following function does nothing. The character passed into the function is a copy of some letter. When you change the letter, it doesn't change the original.

	void f1(char c) {
		c = 'C';
	}

When you pass a pointer to a function, you get a copy of the memory address. But  you can use that address to modify the contents of the original variable.

	void f2(char *c) {
		*c = 'C';
	}

Play with the `pointers.c` file for a bit and then come back for the next part of pointers.

---

One of the most important reason to use pointers is to create arrays. Let's review how to make an array from the stack.

	int s1[5];

So easy. What if you want to return that array from a function? That can't be 
done from the stack. Instead, you have to create an array from the heap. It's surprisingly easy. All you have to do is as `malloc()` to give you the correct amount of memory.

	int *h1 = malloc(5 * sizeof(int));

Now you can read and write to `h1` as an array with the typical square bracket syntax. At `h1[0]` you are accessing the first int-sized piece of memory. At `h1[1]` you are accessing the second int-sized piece of memory.

	for (int i = 0; i < 5; i++) h1[i] = i;

At some point, you will want to clear the memory associated with the heap array.

	free(h1); // eventually

It's not so simple when you get to 2 dimensions. Again, let's see the stack implementation first.

	int s2[4][3];

To make a 2D array on the heap, you first have to allocate an array of pointers, and then allocate an array of values for each of the pointers.

	int **h2 = malloc(4 * sizeof(int*)); // first dimension
	for (int i = 0; i < 4; i++) {
		h2[i] = malloc(3 * sizeof(int)); // second dimension
	}

Reading and writing from stack-based and heap-based arrays is exactly the same. Once you're done with a heap array, you have to free both the rows and columns.

	for (int i = 0; i < 4; i++) free(h2[i]); // free rows
	free(h2); // free columns

So this is all probably sounding like a huge pain in the ass. It is. But it gets worse. What if you decide you want to make the array bigger? You cannot `append()` to heap-based arrays any more than you can stack-based arrays. Instead, you have to create a new array larger than your current array, copy everything over to the new array, and then free the old memory. 

## File I/O ##

Reading files is a little more complicated than in Python. You can read byte-by-byte or line-by-line. Below is the canonical way to read line-by-line. Note that `*line` must be initialized to `NULL` before calling `getline()` (unless you want to allocate your own buffer). If you want to save parts of the input, you will have to copy them to other variables, as the memory underlying `line` gets garbage collected.

	FILE *fp;
	char *line = NULL;
	size_t len;
	ssize_t read;
	
	/* part 1: read a file line-by-line */
	fp = fopen("hello_world.c", "r");
	while ((read = getline(&line, &len, fp)) != -1) {
		printf("read %zu bytes: %s", read, line);
	}
	fclose(fp);
	if (line) free(line);

Writing a file is pretty simple: call `fopen()` with the write flag and then use `fprintf()` to write to the file pointer.

	/* part 2: write a file */
	fp = fopen("testout.txt", "w");
	fprintf(fp, "hello file\n");
	fclose(fp);

## CLI ##

The command line interface is sort of messy. Up until now, we haven't used the fact that `main()` has command line arguments, but it does. `argc` is the number of arguments and `argv` is an array of strings on the command line. `argv[0]` is the name of the program.

	int main(int argc, char *argv[]) {...}

Let's imagine we are writing an entropy filter called `dust` and we want the program to have the following usage statement.

	usage: dust <fasta file>
	  -w <int>   window size [11]
	  -t <float> threshold [1.1]
	  -n         mask with Ns (lowercase default)
	  -h         this message

The program takes one positional argument, a fasta file, and several one-letter options. Processing the command requires a call to `getopt()` with a funny syntax.

	getopt(argc, argv, "w:t:nh"))

A letter followed by a colon is a signal that the option has an argument. If there is no colon, the option has no arguments. Look at the usage statement above and then the string "w:t:nh" and it should make sense.

Processing the entire command line happens in 2 steps. First, the named parameters are pulled from the command line in some kind of a loop.

	while ((opt = getopt(argc, argv, "w:t:nh")) != -1) {
		switch (opt) {
			case 'w':
				window = atoi(optarg);
				break;
			case 't':
				threshold = atof(optarg);
				break;
			case 'n':
				lowercase = 0;
				break;
			case 'h':
				fprintf(stderr, "%s\n%s\n", argv[0], help);
				exit(1);
		}
	}

Once the named parameters are parsed, the reamining positional parameters can be harvested from the command line.

	// positional arguments
	for (int i = optind; i < argc; i++) {
		printf("positional: %s\n", argv[i]);
	}

Unlike Python's argparse, you have to do the usage statement formatting yourself. Take a look at the `cli.c` program.

## Headers ##

Previously, we've included heaer files into our programs like so:

	#include <stdio.h>

Where exactly is the file `stdio.h` located? Buried in your operating system somewhere. When using the `<>` syntax, the compiler knows to look in the _usual_ places. But you can also define your own header files with your own code?

But what _exactly_ is a header file? It contains the definitions for compiled code stored elsewhere, but usually not any operational code. For simplicity, we'll make a header file called `myheader.h` that has actual code in it.

	#include <stdio.h>
	#include <stdlib.h>
	#include <unistd.h>
	void hello_world(void) {
		printf("hello world\n");
	}

Now we'll include everything from the header into our program with `main()`.

	#include "myheader.h"
	int main(int argc, char **argv) {
		hello_world();
	}

The header file is basically our own custom library. However, we don't usually put code into a header file. Instead we compile object files and link those into our program with `main()` later. Just go to the next section.

## Pseudo-OOP ##

In order to maintain my own sanity, I have some very strict rules for programming in C.

1. Objects are pointers to structs
2. All objects are allocated with constructors
3. All objects are freed by destructors
4. Functions never have side-effects

Let's make an an object definition in a header file `biosequence.h`.

	struct biosequence {
		int   len;
		char *def;
		char *seq;
	};
	typedef struct biosequence* BioSeq;

	void   bs_free(BioSeq);
	BioSeq bs_new(const char*, const char*);
	void   bs_print(const BioSeq);
	void   bs_set_line_length(int);

Next, let's make the actual source code in a source file: `biosequence.c`.

	static int LINE_LENGTH = 80;

	void bs_set_line_length(int length) {
		LINE_LENGTH = length;
	}

	void bs_free(BioSeq bs) {
		free(bs->def);
		free(bs->seq);
		bs->def = NULL;
		bs->seq = NULL;
	}

	BioSeq bs_new(const char *def, const char *seq) {
		BioSeq bs = malloc(sizeof(struct biosequence));
		bs->def = malloc(strlen(def) + 1);
		bs->seq = malloc(strlen(seq) + 1);
		bs->len = strlen(seq);
		strcpy(bs->def, def);
		strcpy(bs->seq, seq);
		return bs;
	}

	void bs_print(const BioSeq bs) {
		printf(">%s\n", bs->def);
		for (int i = 0; i < bs->len; i++) {
			putc(bs->seq[i], stdout);
			if ((i+1) % LINE_LENGTH == 0) printf("\n");
		}
		if (bs->len % LINE_LENGTH != 0) printf("\n");
	}

Now let's create a program with a `main()` function that can create and manipulate objects described in the header file and implemented in the source file. We'll call the file `demo.c`.

	#include "biosequence.h"

	int main(int argc, char **argv) {
		BioSeq s1 = bs_new("EcoRI", "GAATTC");
		bs_set_line_length(3);
		bs_print(s1);
		bs_free(s1);
	}

To compile this all together takes 2 steps. First, we have to compile the library into an object file: `biosequence.o`.

	gcc -c biosequence.c

Next, we compile the `demo.c` file as we did before. Except this time we will also include the object file on the command line.

	gcc demo.c biosequence.o

## Make ##

Imagine compiling many files individually and then mashing them all together in the end. Doesn't sound like fun. That's where `make` comes in. A `Makefile` contains instructions for how to build all the intermediate products as well as the final program. Makefiles also tend to have installation and testing routines in them. Note that there are MANY ways of writing Makefiles, and I'm just showing you my method.

At the top of a Makefile we put some definitions. CFLAGS is whatever extra instructions we want to send to the compiler. For example, let's turn on as many warnings as possible and make all warnings into errors.

	CFLAGS = -Wall -Werror
	OBJECTS = biosequence.o

In this section, we also define the name of our program and object file.

	APP = demo
	OBJ = demo.o

The next section of a Makefile is the targets. Usually one just types `make` and the software builds. But you might also want to do `make clean` to remove all of the compiled files or `make test` to test your software. You might also build more than one application at a time.

The `CC` variable is predefined. It's your C compiler (usually gcc).

	default:
		make $(APP)

	$(APP): $(OBJ) $(OBJECTS)
		$(CC) -o $(APP) $(OBJ) $(OBJECTS)

	clean:
		rm -f *.o $(APP)

The last section of a Makefile is the inference rules. This allows you to compile every .c file into a .o file instead of specifiying every file individually.

	%.o: %.c
		$(CC) $(CFLAGS) -c -o $@ $<

You will find `biosequence.h`, `biosequence.c`, `demo.c`, and `Makefile` in the `templates` directory as usual.
