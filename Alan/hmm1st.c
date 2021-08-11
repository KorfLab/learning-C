//1st order hmm

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void print_matrix(double**, int, int);
int findex(char*, int, char);
void display_data(char*, double**, int, int); 

int main() {
	char seq[100] = 		"TCTTTTGGCGCACAAATGCTCAGCACCATTTAAATTAGACCGACTCCAGATCTGTAAGGTCCGCCACGCAGACGACAGCCCACGGAGACCACTGACCGAT";
	printf("%s\n\n", seq);
	
	char bases[4] = {'A', 'C', 'G', 'T'};
	
	//create 2 arrays to mimic a dictionary
	
	char *kmer_value = malloc(4 * sizeof(char));
	for (int i = 0; i < 4; i++) {
		kmer_value[i] = bases[i];
	}
	
	for (int i = 0; i < 4; i++) {
		printf("%c ", kmer_value[i]);
	}
	printf("\n\n");
	
	/*
	kmer_key[4][4] -> [4 -> corresponds to kmer_value][4 -> A C G T]
	0 -> A
	1 -> C
	2 -> G
	3 -> T
	*/
	
	double **kmer_key = malloc(4 * sizeof(double*));
	for (int i = 0; i < 4; i++) kmer_key[i] = malloc(sizeof(double));
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) kmer_key[i][j] = 0;
	}
	
	//fill in the kmer_key
	int index;
	int base;
	for (int i = 1; i < 100; i++) {
		index = findex(kmer_value, 4, seq[i-1]);
		switch(seq[i]) {
			case 'A': base = 0; break;
			case 'C': base = 1; break;
			case 'G': base = 2; break;
			case 'T': base = 3; break;
			default: printf("wtf");
		}
		kmer_key[index][base] += 1;
	}
	display_data(kmer_value, kmer_key, 4, 4);

	//process absolute frequency into relative frequency
	double sum;
	for (int i = 0; i < 4; i++) {
		sum = kmer_key[i][0] + kmer_key[i][1] + kmer_key[i][2] + kmer_key[i][3];
		for (int j = 0; j < 4; j++) kmer_key[i][j] = kmer_key[i][j]/sum;
	}
	
	//display the data table	
	display_data(kmer_value, kmer_key, 4, 4);
}

void display_data(char *kmer_value, double **kmer_key, int l1, int l2) {
	printf("	A	        C	        G	        T\n");
	for (int i = 0; i < l1; i++) {
		printf("%c	", kmer_value[i]);
		for (int j = 0; j < l2; j++) printf("%f	", kmer_key[i][j]);
		printf("\n");
	}
	printf("\n");
}

void print_matrix(double **matrix, int l1, int l2) {
	for (int i = 0; i < l1; i++) {
		for (int j = 0; j < l2; j++) printf("%f	", matrix[i][j]);
		printf("\n");
	}
	printf("\n");

}

int findex(char *array, int len, char element) {
	int index = -1;
	for (int i = 0; i < len; i++) {
		if (array[i] == element) index = i;
	}
	return index;
}
