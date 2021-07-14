#include <stdio.h>
#include <math.h>

int main() {
	int a;     // declaring a variable
	int b, c;  // declaring multiple variables of the same type
	int d = 0; // declarating and assigning at the same time
	float e;
	printf("%d %d %d %d %lf\n", a, b, c, d, e); // %d for digit
	
	// char is a character and also an 8-bit integer
	char nt = 'A'; // single characters are in single quotes
	printf("%c %d\n", nt, nt); // ASCII value of A is 65

	// there are many flavors of integers
	char i1;           // -128 to 127
	unsigned char i2;  // 0 to 255
	short i3;          // -32768 to 32767
	unsigned short i4; // 0 to 65536
	long i5;           // depends, see limits.h
	unsigned long i6;  // depends, see limits.h

	// there are two common flavors of floats
	float f1 = M_PI;       // 1.2e-38 to 3.4e+38
	double f2 = M_PI;      // 2.3e-308 to 1.7e+308
	printf("%f %f\n", f1, f2);
	printf("%.3f\n", f2);  // limiting precision

	// there are even more types of variables!

	// Ian's play area
	float wtf1;
	double wtf2;
	double pi2 = 2 * M_PI;
	printf("%f %f %f\n", wtf1, wtf2, pi2);
	
}

