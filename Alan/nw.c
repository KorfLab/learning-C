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

void print_matrix(int l1, int l2) {
	printf("Hello world\n");
	for(int i = 0; i < l1; i++) {
		for(int j = 0; j < l2; j++) {
			printf("i = %d, j = %d, s = %d, trace = %c\n", i, j, 				matrix[i][j].score, matrix[i][j].trace);
		}
	}
}

int main(int argc, char **argv) {
	
	int match = 1;
	int mismatch = -1;
	int gap = -1;
	
	char *s1 = argv[1];
	char *s2 = argv[2];
	
	for(int i = 0; i < 100; i++) {
		for(int j = 0; j < 100; j++) {
			matrix[i][j].score = 0;
			matrix[i][j].trace = 'a';
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
	
	
	print_matrix(3,3);
	printf("%s, %s\n", s1, s2);
	
	
}


