#include <stdio.h>
#include <string.h>

int main() {
	char c = 'A';          // c holds one character
	char s1[10];           // s1 is big enough for 10 letters
	char s2[10] = "abcde"; // s2 using 6/10 letters (yes, 6, see below)
	
	// when you allocate a string, it may have random stuff
	//printf("%s\n", s1); // remove comment to observe
	
	// %s is used in printf() for formatting strings
	printf("string: %s\n", s2);
	
	// edit strings by changing letter at indices
	s2[1] = 'B';          
	printf("editing one letter: %s\n", s2);
	
	// all strings end with \0
	s2[1] = '\0';
	printf("suddenly shorter: %s\n", s2);
	// go back and think about what printf("%s", s1) does...
	
	// use strlen() to get length, and sizeof() to get memory footprint
	printf("len:%lu size:%lu\n", strlen(s2), sizeof(s2));
	
	// what happens if you try to go beyond 10 characters?
	//s2[12] = 'b'; // possibly nothing, possibly the end of the world
	// stop and consider if you really want to program in C
	
	// another way to create a string is with a pointer (star symbol)
	char *s3 = "ACGT"; // strings created like this are read-only
	printf("%d == %d?\n", (int)strlen(s3), (int)sizeof(s3)); // and not as long
	
	// making interesting strings
	char strbuff[64]; // create a string buffer
	sprintf(strbuff, "%s %.3f", "PI-ish", 3.14159); // then sprintf()
	printf("%s\n", strbuff);
	
	// copying strings
	strcpy(strbuff, "overwritten"); // you can copy one string into another
	printf("%s\n", strbuff);
	
}

