#include <stdio.h>
#include <stdlib.h>

void f1(char c) {
	c = 'C';
}

void f2(char *c) {
	*c = 'C';	
}

int main() {
	char c = 'A';
	char *p;
	
	printf("pointers are %lu bytes\n", sizeof(p));
	
	p = &c; // p now contains the memory address of c
	printf("contents: %c, address: %lu\n", c, p);
	
	*p = 'B';
	printf("contents: %c, address: %lu\n", c, p);
	
	f1(c); // passing the value of c
	printf("changed? %s\n", c == 'C' ? "yes": "no");
	
	f2(&c); // passing the memory location of c
	printf("changed? %s\n", c == 'C' ? "yes": "no");
	
}
