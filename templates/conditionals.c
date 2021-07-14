#include <stdio.h>
#include <string.h>

int main() {
	int a = 1;
	
	if (a == 1) printf("a is 1\n"); // one-line conditional
	
	// the typical if-else construction
	if (a == 2) {
		printf("a is 2");
	} else if (a == 3) {
		printf("a is 3");
	} else {
		printf("a is actually %d\n", a);
	}
	
	// the typical for loop
	// note the loop variable declaration _inside_ the loop
	// note the ++ operator to increment by one
	for (int i = 0; i < 5; i++) printf("%d ", i); // one-line loop
	printf("done with i\n");
	//printf("%d\n", i); // this is an error! yes!
	
	// you can also declare the loop variable outside the loop
	int j;
	for (j = 0; j < 5; j++) {
		printf("%d ", j); // block structure loop
	}
	printf("done with j\n");
	printf("j = %d\n", j); // j still exists, which can be bad for debugging
	
	// let's loop over letters of DNA for fun
	char dna[5] = "ACGT";
	for (int i = 0; i < strlen(dna); i++) {
		printf("%d %c\n", i, dna[i]);
	}
	
	// the while loop should look familiar
	while (1) { // this is a never-ending loop
		printf("while %d\n", j);
		if (j++ == 7) break; // use break to stop any loop or conditional
	}
	
	// the continue statement short-circuits to start of loop
	for (int k = 0; k < 5; k++) {
		if (k == 2) continue;
		printf("%d ", k);
	}
	printf("done with k\n");
	
	/*
	
	The following conditional constructs are less commonly used:
	
	+ ternary operator
	+ switch-case
	+ do loop
	+ labels and goto
	
	*/
	
	// the ternary operator is a one-line if-else
	a = 1;
	printf("is a 1? %s\n", a == 1 ? "yes" : "no");
	
	// switch-case
	int b = 2;
	switch(b) {
		case 0:
			printf("b is 0\n");
			break; // you need break statements or there is fall-through
		case 1:
			printf("b is 1\n");
			break;
		case -1:
			printf("b is -1\n");
			break;
		default:
			printf("b is actually %d\n", b);
	}
	
	// the do loop is like the while loop but always executes once
	j = 2;
	do {
		printf("yo %d\n", j);
	} while (j < 0); // weirdly requires semicolon
	
	// you can label code blocks and use goto...
	int c = 0;
	WTF: {
		printf("this is weird %d\n", c);
		c++;
	}
	if (c < 2) goto WTF;
	else       goto THE_END;
	
	printf("this is never executed\n");
	
	THE_END: {printf("and so it is\n");}	

}

