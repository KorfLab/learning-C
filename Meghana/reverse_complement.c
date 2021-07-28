#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// reverse complement 
char* rc(const char *seq) {
	char *anti = malloc(strlen(seq)+1);
	for (int k = 0; k < strlen(seq); k++) {
		switch(seq[k]){
		case 'A': anti[strlen(seq)-k-1] = 'T';break;
		case 'T': anti[strlen(seq)-k-1] = 'A';break;
		case 'G': anti[strlen(seq)-k-1] = 'C';break;
		case 'C': anti[strlen(seq)-k-1] = 'G';break;
		default: anti[strlen(seq)-k-1] = 'N';
		}

	}
	return anti;
}
int main (int argc, char **argv) {
	char *reverse_complement;
	reverse_complement = rc(argv[1]);
	printf("%s\n", reverse_complement);

}

