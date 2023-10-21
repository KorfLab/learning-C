#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int months = atoi(argv[1]);
	int rate = atoi(argv[2]);
	
	printf("%d months at a rate of %d\n", months, rate);
	
	long num1 = 1;
	long num2 = 1;
	long num3;
	
	for (int i = 0; i < months-2; i++) {
		num3 = rate * num1 + num2;
		num1 = num2;
		num2 = num3;
	}
	
	printf("population = %lu\n", num3);
}
