//2nd order hmm -> 16 values {AA, AC, AG, AT, CA, CC, CG, CT,...}

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main() {
	char seq[100] = "TCTTTTGGCGCACAAATGCTCAGCACCATTTAAATTAGACCGACTCCAGATCTGTAAGGTCCGCCACGCAGACGACAGCCCACGGAGACCACTGACCGAT";
	printf("%s\n\n", seq);
	
	char bases[4] = {'A', 'C', 'G', 'T'};
	
	//create 2 arrays to mimic a dictionary
	
	//kmer_value[16][2] -> [16 possible kmers][2-mers]
	char **kmer_value = malloc(16 * sizeof(char*));
	for (int i = 0; i < 16; i++) {
		kmer_value[i] = malloc(2 * sizeof(char));
	}
	
	//initializing all possible kmers
	for (int i = 0; i < 16; i++) {
		kmer_value[i][0] = bases[(i/4)];
	}
	for (int i = 0; i < 16; i++) {
		kmer_value[i][1] = bases[(i%4)];
	}
	
	//display all possible kmers
	for (int i = 0; i < 16; i++) {
		for(int j = 0; j < 2; j++) {
			printf("%c", kmer_value[i][j]);
		}
		printf(" ");
	}
	printf("\n");
	
	//kmer key
	
}
