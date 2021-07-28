#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cell {
	int score;
	char trace;
}; 
typedef struct cell Cell;

struct cell matrix[100][100];

/*
Cell new_cell(int *score, char *trace){
	Cell new_cell = malloc(sizeof(struct cell));
	new_cell->score = malloc(sizeof(int));
	new_cell->trace = malloc(3 * sizeof(char));
	new_cell->score = score;
	for(int i = 0; i <3; i++) new_cell->trace[i] = trace[i];
}

void free_cell(Cell the_cell){
	free(the_cell->score);
	for(i = 0; i <3; i++){
		free(the_cell->trace[i]);
	}
	free(the_cell->trace);
}
*/

void print_matrix(int l1, int l2);
int max(int array[]);

int main(int argc, char **argv) {
	
	int match = 1;
	int mismatch = -1;
	int gap = -1;
	
	char *s1 = argv[1];
	char *s2 = argv[2];
	int l1 = strlen(s1);
	int l2 = strlen(s2);
	
	for(int i = 0; i < 100; i++) {
		for(int j = 0; j < 100; j++) {
			matrix[i][j].score = 0;
			matrix[i][j].trace = 'N';
		}
	}
	
	//initialization
	for(int i = 1; i <= strlen(s1); i++) {
		matrix[i][0].score = gap * i;
		matrix[i][0].trace = 'L';
	}
	
	for(int j = 1; j <= strlen(s2); j++) {
		matrix[0][j].score = gap * j;
		matrix[0][j].trace = 'U';
	}
	
	//fill
	for(int i = 0; i <= l1; i++) {
		for(int j = 0; j <= l2; j++) {
			//current cell is matrix[i+1][j+1]
			int left = matrix[i+1][j].score + gap;
			int up = matrix[i][j+1].score + gap;
			int diag = (s1[i]==s2[j])? 
			matrix[i][j].score + match :
			matrix[i][j].score + mismatch;
			
			int path[3] = {left, up, diag};
			matrix[i+1][j+1].score = max(path); 

			
			if(matrix[i+1][j+1].score == left) matrix[i+1][j+1].trace = 'L';
			if(matrix[i+1][j+1].score == up  ) matrix[i+1][j+1].trace = 'U';
			if(matrix[i+1][j+1].score == diag) matrix[i+1][j+1].trace = 'D';
			
		}
	}
	
	//trace back
	int l3 = 0;
	int r = l1;
	int c = l2;
	while(r!=0) {
		if(matrix[r][c].trace=='L') {
			c-=1;
			l3+=1;
		}
		else {
			if(matrix[r][c].trace=='U') {
				r-=1;
				l3+=1;
			}
			else {
				c-=1;
				r-=1;
				l3+=1;
			}
		}	
	}
	
	char *matched_s1 = malloc(l3 * sizeof(char));
	char *matched_s2 = malloc(l3 * sizeof(char));
	
	r = l1;
	c = l2;
	int counter = l3;
	//printf("r = %d, c = %d\n", r, c);
	while(r!=0) {
		if(matrix[r][c].trace=='L') {
			matched_s1[counter-1] = '-';
			matched_s2[counter-1] = s2[c-1];
			c -= 1;
			counter -= 1;
			//printf("r = %d, c = %d, l3 = %d\n", r, c, counter);
		}
		else {
			if(matrix[r][c].trace=='U') {
				matched_s1[counter-1] = s1[r-1];
				matched_s2[counter-1] = '-';
				r -= 1;
				counter -= 1;
				//printf("r = %d, c = %d, l3 = %d\n", r, c, counter);
			}
			else {
				matched_s1[counter-1] = s1[r-1];
				matched_s2[counter-1] = s2[c-1];
				c -= 1;
				r -= 1;
				counter -= 1;
				//printf("r = %d, c = %d, l3 = %d\n", r, c, counter);
		
			}	
		}
	}
	
		
	//print_matrix(l1,l2);
	
	for(int i = 0; i < l3; i++) {
		printf("%c ", matched_s1[i]);
	}
	printf("\n");
	for(int j = 0; j < l3; j++) {
		printf("%c ", matched_s2[j]);
	}
	printf("\n");
	
	
	
}

int max(int array[]) {
	int max = array[0];
	for(int i = 0; i < 3; i++) {
		if (array[i] > max) max = array[i];
	}
	return max;
}

void print_matrix(int l1, int l2) {
	/*
	for(int i = 0; i <= l1; i++) {
		for(int j = 0; j <= l2; j++) {
			printf("i = %d, j = %d, s = %d, trace = %c\n", i, j, 				matrix[i][j].score, matrix[i][j].trace);
		}
	}*/
	
	for(int i = 0; i <= l1; i++) {
		for(int j = 0; j <= l2; j++) {
			printf("%d	", matrix[i][j].score);
		}
		printf("\n");
	}
	printf("\n");
	for(int i = 0; i <= l1; i++) {
		for(int j = 0; j <= l2; j++) {
			printf("%c	", matrix[i][j].trace);
		}
		printf("\n");
	}
}

