//nth order hmm -> 4^n values {AA, AC, AG, AT, CA, CC, CG, CT,...}

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main() {
	char seq[100] = "TCTTTTGGCGCACAAATGCTCAGCACCATTTAAATTAGACCGACTCCAGATCTGTAAGGTCCGCCACGCAGACGACAGCCCACGGAGACCACTGACCGAT";
	printf("%s\n\n", seq);
	
	char bases[4] = {'A', 'C', 'G', 'T'};
	int n = 4;
	int num_kmer = 1;
	for (int i = 0; i < n; i++) num_kmer*=4;
	printf("%d \n", num_kmer);
	//create 2 arrays to mimic a dictionary
	
	//kmer_value[16][2] -> [16 possible kmers][2-mers]
	char **kmer_value = malloc(num_kmer * sizeof(char*));
	for (int i = 0; i < num_kmer; i++) {
		kmer_value[i] = malloc(n * sizeof(char));
	}
	
	int c = num_kmer/4;
	//initializing all possible kmers
	for (int j = 0; j < n; j++) {
		for(int i = 0; i < num_kmer; i++) {
			kmer_value[i][j] = bases[(i/c)%4];
		}
		c = c/4;
	}
	
	//display all possible kmers
	for (int i = 0; i < num_kmer; i++) {
		for(int j = 0; j < n; j++) {
			printf("%c", kmer_value[i][j]);
		}
		printf(" ");
	}
	printf("\n");
	
	//kmer key
	
}
