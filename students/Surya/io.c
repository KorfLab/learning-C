#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *fp;
	char *line = NULL;
	size_t len;
	ssize_t read;
	
	/* part 1: read a file line-by-line */
	fp = fopen("hello_world.c", "r");
	while ((read = getline(&line, &len, fp)) != -1) {
		printf("read %zu bytes: %s", read, line);
	}
	fclose(fp);
	if (line) free(line);
	
	/* part 2: write a file */
	fp = fopen("testout.txt", "w");
	fprintf(fp, "hello file\n");
	fclose(fp);
		
}

