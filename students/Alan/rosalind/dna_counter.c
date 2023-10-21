#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
	char *seq = argv[1];
	int len = strlen(seq);
	printf("sequence: %s\n", seq);
	printf("length: %d\n", len);
	
	int a = 0;
	int c = 0;
	int g = 0;
	int t = 0;
	for (int i = 0; i < len; i++) {
		switch(seq[i]) {
			case 'A': a++; break;
			case 'C': c++; break;
			case 'G': g++; break;
			case 'T': t++; break;
			default: printf("WTF");	
		}
	}
	
	printf("%d %d %d %d\n", a, c, g, t);
}
