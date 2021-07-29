#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cell {
	int score;
	char trace;
}; 
typedef struct cell Cell;

struct cell matrix[100][100];

void print_matrix(int, int);

int main(int argc, char **argv) {
	
	int match = 1;
	int mismatch = -1;
	int gap = -1;
	
	char *s1 = argv[1];
	char *s2 = argv[2];
	int l1 = strlen(s1);
	int l2 = strlen(s2);
	
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			matrix[i][j].score = 0;
			matrix[i][j].trace = 'N';
		}
	}
	
	//initialization
	for (int i = 1; i <= strlen(s1); i++) {
		matrix[i][0].score = gap * i;
		matrix[i][0].trace = 'L';
	}
	
	for (int j = 1; j <= strlen(s2); j++) {
		matrix[0][j].score = gap * j;
		matrix[0][j].trace = 'U';
	}
	
	//fill
	for (int i = 1; i <= l1; i++) {
		for (int j = 1; j <= l2; j++) {
			
			int left = matrix[i][j-1].score + gap;
			int up = matrix[i-1][j].score + gap;
			int diag = (s1[i-1]==s2[j-1])
				? matrix[i][j].score + match 
				: matrix[i][j].score + mismatch;
			
			if (left > up && left > diag) {
				matrix[i][j].score = left;
				matrix[i][j].trace = 'L';
			}
			else if (up > diag) {
				matrix[i][j].score = up;
				matrix[i][j].trace = 'U';
			}
			else {
				matrix[i][j].score = diag;
				matrix[i][j].trace = 'D';
			}	
		}
	}
	
	//trace back
	char *matched_s1 = malloc(l1 + l2);
	char *matched_s2 = malloc(l1 + l2);
	int i = l1;
	int j = l2;
	int counter = 0;
	
	while (i != 0 && j != 0) {
		if (matrix[i][j].trace=='L') {
			matched_s1[counter] = '-';
			matched_s2[counter] = s2[j-1];
			j -= 1;
			counter += 1;
		}
		else if (matrix[i][j].trace=='U') {
			matched_s1[counter] = s1[i-1];
			matched_s2[counter] = '-';
			i -= 1;
			counter += 1;
		}
		else {
			matched_s1[counter] = s1[i-1];
			matched_s2[counter] = s2[j-1];
			i -= 1;
			j -= 1;
			counter += 1;
		}	
	}
	
	//Display matrix
	print_matrix(l1,l2);
	
	//Print alignments
	for (int i = counter-1; i >= 0; i--) {
		printf("%c ", matched_s1[i]);
	}
	printf("\n");
	for (int j = counter-1; j >= 0; j--) {
		printf("%c ", matched_s2[j]);
	}
	printf("\n");
	
	//free memory
	free(matched_s1);
	free(matched_s2);
	
	
	
}


void print_matrix(int l1, int l2) {
	for (int i = 0; i <= l1; i++) {
		for (int j = 0; j <= l2; j++) {
			printf("%d	", matrix[i][j].score);
		}
		printf("\n");
	}
	
	printf("\n");
	
	for (int i = 0; i <= l1; i++) {
		for (int j = 0; j <= l2; j++) {
			printf("%c	", matrix[i][j].trace);
		}
		printf("\n");
	}
}

