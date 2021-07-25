#include "biosequence.h"

int main(int argc, char **argv) {
	BioSeq s1 = bs_new("EcoRI", "GAATTCA");
	bs_set_line_length(3);
	bs_print(s1);
	bs_free(s1);
}

