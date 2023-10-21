//nth order hmm -> 4^n values {AA, AC, AG, AT, CA, CC, CG, CT,...}

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int findex(char**, int, char*);
void display_data(char**, double**, int, int, int);

int main() {
	char seq[1000] = "AGACAGAGAAACGGCCGAATACGCCTGTTCGTGTCGTATCGGTAAGCAGCCCCGCGGAGCCATGTGCCATACCGGTCCGCGGAGCACTCCGGTTGCGCGTGCGGTCCGCAGGACGCCCGTCGCTTCCGGGCGTGCGCTCTGCGTGACGGCCCCTAGGCGCACTGGTGCTCGGCGCCACCTAAGCCGGACCGGCACCAGACCTGCAAGGTCCGCCACGCAGGCGGCGGCCCGCGGGGACCGCCGGCCGATCCACCCGATCGGCGACCGTCTGTGTGGCACTGGGGCGGGGAGGTAACTACGGCGCCGCTAACAGCCCCCCTGTCGTCGCCGACGTCTGTGGTCTGGCCTCGTTGTGGTTGCACGCTATCCGGGGATCGGCTGATGCCGGGGGACACCCCGGTTGAAGCGGCCTATGCGACAGAGACCGTGCACCCACCGGGTCTCCTTAGTGTAGGTTCGGACCGACTGGCGGTTCGTCCAGAACCCAGATTCTAACAGCAGGGGACGCGTGCCCTACCCCCATGATCCACTGGCGTCCCTGAGGCCGCAGTACATGCGGCGGGGCGGCCCCCGCGGCAAGCCCTAGTGCAATGGCGCTTTCCCACCCTCGTCCCCGGGAAGAGGGGGCGCCGGTGCGGGCATCCCTAGTGCGGTAACTGGGGGGGCTCCCGGCCCTCCGCCCTTAGGCGGTGCGTGCCCCTCCGTAGACGGGCTGCCAGTCATGGCGCCCGAGGATCCGAGAAGGCGAGCGGGCCCGGCCGACCCGGGGGGACGGGCCTCAAAGCCGCCCGGCGACGGCTGCGCGCCCGTATCAGAACCCCCCCAGTGAGCCCCCGTCGCCGTCGGTTGAAGAGCCCAGGACGGGCCGGCCAGGCGCGCGATCACGTCGCTCGACGGCTCCCGGGCCGCGGCGCGTTGCCTTGCGGGAATCGAGGCCGTCCGTCGATTCCCCTTGCGTACGTACCGCGTTCTTTTGTCTCTTTGCCCGCTTACCTGGACA";
	printf("%s\n\n", seq);
	int n = 4; //nth hmm
	
	char bases[4] = {'A', 'C', 'G', 'T'};
	int num_kmer = 1;
	for (int i = 0; i < n; i++) num_kmer*=4;
	
	/*
	Create 2 arrays to mimic a dictionary
	> kmer_value - stores all possible kmer combinations
	> kmer_key   - sores the emission probability given the kmer combination
	*/
	
	//kmer_value[num_kmer][n] -> [num_kmer possible kmers][n-mers]
	char **kmer_value = malloc(num_kmer * sizeof(char*));
	for (int i = 0; i < num_kmer; i++) kmer_value[i] = malloc(n * sizeof(char));
	
	//initializing all possible kmers
	int c = num_kmer/4;
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < num_kmer; i++) kmer_value[i][j] = bases[(i/c)%4];
		c = c/4;
	}
	
	//display all possible kmers
	for (int i = 0; i < num_kmer; i++) printf("%s ", kmer_value[i]);
	printf("\n\n");
	
	/*
	kmer_key[num_kmer][4] -> [num_kmer possible kmers][emission probabilities for ACGT]
	0 -> A
	1 -> C
	2 -> G
	3 -> T
	*/
	double **kmer_key = malloc(num_kmer * sizeof(double*));
	for (int i = 0; i < num_kmer; i++) kmer_key[i] = malloc(4 * sizeof(double));
	//pre-initialize the kmer_key
	for (int i = 0; i < num_kmer; i++) {
		for (int j = 0; j < 4; j++) kmer_key[i][j] = 0;
	}
	
	
	//fill in the kmer_key
	int index;
	int base;
	char *temp = malloc(n * sizeof(char));
	
	for (int i = n; i < 1000 /*length of seq*/; i++) {
		for (int j = i-n; j < i; j++) temp[n+j-i] = seq[j];
		index = findex(kmer_value, num_kmer, temp);
		switch(seq[i]) {
			case 'A': base = 0; break;
			case 'C': base = 1; break;
			case 'G': base = 2; break;
			case 'T': base = 3; break;
			default: printf("wtf");
		}
		kmer_key[index][base] += 1;
	}
	
	//process absolute frequency into relative frequency
	double sum;
	for (int i = 0; i < num_kmer; i++) {
		sum = kmer_key[i][0] + kmer_key[i][1] + kmer_key[i][2] + kmer_key[i][3];
		if (sum != 0) for (int j = 0; j < 4; j++) kmer_key[i][j] = kmer_key[i][j]/sum;
		else for (int j = 0; j < 4; j++) kmer_key[i][j] = 0;
	}
	
	
	//display the data table	
	display_data(kmer_value, kmer_key, num_kmer, 4, n);
	
	
}

void display_data(char **kmer_value, double **kmer_key, int l1, int l2, int n) {
	for (int i = 0; i < n; i++) printf(" ");
	printf("    A           C	       G	   T\n");
	for (int i = 0; i < l1; i++) {
		printf("%s    ", kmer_value[i]);
		for (int j = 0; j < l2; j++) printf("%.6f    ", kmer_key[i][j]);
		printf("\n");
	}
	printf("\n");
}

int findex(char **kmer_value, int len, char *target) {
	int index = -1;
	for (int i = 0; i < len; i++) {
		if (strcmp(kmer_value[i],target) == 0) {
			index = i;
			break;
		}		
	}
	return index;
}











