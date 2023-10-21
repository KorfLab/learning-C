#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int az_index(const char*, int, int); 

int main() {
	char *seq = "ACGTtGCTGATnCGTTTAAGGCACTGAT";
	char buff[16];
	int k = 3;
	int size = (int)pow(4,k);
	int *count = malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++) count[i] = 0;
	double total = 0;
	for(int i = 0; i < strlen(seq)-k+1; i++) {
		strncpy(buff, seq+i, k);
		buff[k] = '\0';
		int idx = az_index(seq, i, k);
		if (idx!=-1) {
			count[idx]++;
			total++;
		}
	}
	double sum = 0;
	for (int i = 0; i < size; i++) {
		printf("%d, %d, %f\n", i, count[i], count[i]/total);
		sum += count[i]/total;
	}
	printf("%f\n", sum);
}

int az_index(const char *seq, int off, int k) {
	int idx = 0;
	for (int i = 0; i < k; i++) {
		switch (seq[i+off]) {
			case 'A': case 'a': idx+= pow(4,(k-i-1)) * 0; break;
			case 'C': case 'c': idx+= pow(4,(k-i-1)) * 1; break;
			case 'G': case 'g': idx+= pow(4,(k-i-1)) * 2; break;
			case 'T': case 't': idx+= pow(4,(k-i-1)) * 3; break;
			default: return -1;
		}
	}
	return idx;
}


