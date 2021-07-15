#include <stdio.h>

// functions are generally in global scope

static int sumi(int a, int b) {
	return a + b;
}

static float sumf(float a, float b) {
	return a + b;
}

static int Var = 3;       // a variable in global scope
static const int VAR = 3; // a constant in global scope


int main() {
	// functions have specific types of inputs and outputs
	printf("sum: %d\n", sumi(1, 3));
	printf("sum: %f\n", sumf(1.1, 3.1));
	
	printf("before: %d\n", Var);
	Var = 4;
	printf("after: %d\n", Var);
	//VAR = 4; // no, you can't do this
}

