#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	char *seq1 = argv[1];
	int len = strlen(seq1);
	char *seq2 = malloc(len);
	
	
	for (int i = len-1; i >= 0; i--) {
		switch(seq1[i]) {
			case 'A': seq2[len-i-1] = 'T'; break;
			case 'C': seq2[len-i-1] = 'G'; break;
			case 'G': seq2[len-i-1] = 'C'; break;
			case 'T': seq2[len-i-1] = 'A'; break;
			default: printf("wtf");
		}
		putc(seq2[len-i-1], stdout);
	}
	printf("\n");
	
}
