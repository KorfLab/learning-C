#include <stdio.h>
#include <stdlib.h>


int main() {
	// 1 dimension stack - automatic garbage collection
	int s1[5]; // allocate
	for (int i = 0; i < 5; i++) s1[i] = i; // fill
	for (int i = 0; i < 5; i++) printf("1d stack %d %d\n", i, s1[i]); // read
	
	// 1 dimension heap
	int *h1 = malloc(5 * sizeof(int)); // allocate
	for (int i = 0; i < 5; i++) h1[i] = i; // fill
	for (int i = 0; i < 5; i++) printf("1d heap %d %d\n", i, h1[i]); // read
	free(h1); // manual garbage collection
	
	// 2 dimensions stack - automatic garbage collection
	int s2[4][3]; // allocate
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
				s2[i][j] = i + j; // fill
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			printf("2d stack %d %d %d\n", i, j, s2[i][j]); // read
		}
	}
	
	// 2 dimensions heap
	int **h2 = malloc(4 * sizeof(int*)); // first dimension
	for (int i = 0; i < 4; i++) {
		h2[i] = malloc(3 * sizeof(int)); // second dimension
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
				h2[i][j] = i + j; // fill
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			printf("2d heap %d %d %d\n", i, j, h2[i][j]); // read
		}
	}
	for (int i = 0; i < 4; i++) free(h2[i]); // free rows
	free(h2); // free columns
	
}
