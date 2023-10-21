/*****************************************************************************\
biosequence.c
\*****************************************************************************/

#ifndef BIOSEQUENCE_C
#define BIOSEQUENCE_C

#include "biosequence.h"

static int LINE_LENGTH = 80;

void bs_set_line_length(int length) {
	LINE_LENGTH = length;
}

void bs_free(BioSeq bs) {
	free(bs->def);
	free(bs->seq);
	bs->def = NULL;
	bs->seq = NULL;
}

BioSeq bs_new(const char *def, const char *seq) {
	BioSeq bs = malloc(sizeof(struct biosequence));
	bs->def = malloc(strlen(def) + 1);
	bs->seq = malloc(strlen(seq) + 1);
	bs->len = strlen(seq);
	strcpy(bs->def, def);
	strcpy(bs->seq, seq);
	return bs;
}

void bs_print(const BioSeq bs) {
	printf(">%s\n", bs->def);
	for (int i = 0; i < bs->len; i++) {
		putc(bs->seq[i], stdout);
		if ((i+1) % LINE_LENGTH == 0) printf("\n");
	}
	if (bs->len % LINE_LENGTH != 0) printf("\n");
}

#endif
