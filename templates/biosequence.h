/*****************************************************************************\
biosequence.h
\*****************************************************************************/

#ifndef BIOSEQUENCE_H
#define BIOSEQUENCE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct biosequence {
	int   len;
	char *def;
	char *seq;
};
typedef struct biosequence* BioSeq;

void   bs_free(BioSeq);
BioSeq bs_new(const char*, const char*);
void   bs_print(const BioSeq);
void   bs_set_line_length(int);

#endif
