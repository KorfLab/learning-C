#include <stdio.h>
#include <stdlib.h>

#define MEMSIZE 1024

void stack(void) {
	char mem[MEMSIZE];
	printf("allocated %d from stack\n", MEMSIZE);
}

void heap(void) {
	char *mem = malloc(MEMSIZE);
	printf("allocated %d from heap\n", MEMSIZE);
}

char *proper(void) {
	char *mem = malloc(MEMSIZE);
	printf("allocated %d from heap\n", MEMSIZE);
	return mem;
}

int main() {
	while (1) stack();
	//while (1) heap();
	/*
	char* mem;
	while (1) {
		mem = proper();
		free(mem);
		printf("freed %d from heap\n", MEMSIZE);
	}
	*/
}
