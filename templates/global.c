#include <stdio.h>
#include <string.h>

#define MAX_SIZE 10

static const char *VERSION = "0.1"; // a private constant in global scope

static int Squares[MAX_SIZE]; // a private global array

// a private function that reads from a global variable
static void print_square(int idx) {
	printf("The square of %d is %d\n", idx, Squares[idx]);
}


int main() {
	printf("Program version: %s\n", VERSION);
	for (int i = 0; i < MAX_SIZE; i++) {
		Squares[i] = i * i;
	}
	
	for (int i = 0; i < MAX_SIZE; i++) print_square(i);
}

