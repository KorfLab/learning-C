#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static char *help= "\
usage: dust <fasta file>\n\
  -w <int>   window size [11]\n\
  -t <float> threshold [1.1]\n\
  -n         mask with Ns (lowercase default)\n\
  -h         this message";

int main(int argc, char *argv[]) {
	int opt;
	int window = 11;
	double threshold = 1.1;
	int lowercase = 1;
	
	// named parameters
	while ((opt = getopt(argc, argv, "w:t:nh")) != -1) {
		switch (opt) {
			case 'w':
				window = atoi(optarg);
				break;
			case 't':
				threshold = atof(optarg);
				break;
			case 'n':
				lowercase = 0;
				break;
			case 'h':
				fprintf(stderr, "%s\n", help);
				exit(1);
		}
	}
	printf("window %d, threshold %f, lowercase %s\n", window, threshold,
		lowercase ? "yes" : "no");
	
	// positional arguments
	for (int i = optind; i < argc; i++) {
		printf("positional: %s\n", argv[i]);
	}
		
}

