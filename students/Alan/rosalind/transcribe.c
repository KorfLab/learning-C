#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	char *dnaseq = argv[1];
	int len = strlen(dnaseq);

	char *rnaseq = malloc(len);
	for (int i = 0; i < len; i++) {
		rnaseq[i] = (dnaseq[i] == 'T') ? 'U' : dnaseq[i];
		putc (rnaseq[i], stdout);
	}
	printf("\n");
}
