#include <stdio.h>

int main() {
	// creating an array is simple
	// set the size in []
	// set the values in {}
	int val[5] = {0, -1, 2, 7, -3};
	printf("value at index 3: %d\n", val[3]);
	
	// there is nothing to prevent you from doing something idiotic
	int bad[5] = {0, 1};
	printf("who knows?: %d\n", bad[4]); // uninitialized values
	
	// there is no append() or push() because arrays have fixed size
	int array[100];
	array[0] = 3;
	array[1] = 5;
	array[2] = -1;
	
	// there is no way of knowing how much of an array is in use
	printf("size: %lu %lu\n", sizeof(int), sizeof(array));
	
	// you have to keep track of these things yourself
	for (int i = 0; i <= 2; i++) {
		printf("index:%d value:%d\n", i, array[i]); 
	}
	
	// 2-dimensional array
	int mat[3][3] = {
		{0, 1, 2},
		{3, 6, 5},
		{6, 7, 8}
	};
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d %d %d\n", i, j, mat[i][j]);
		}
	}
	
}

