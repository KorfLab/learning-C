#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct food {
	int cal;
	int protein;
	int fat;
	int carb;
	char *name;
};

typedef struct food* Food;

int main(){
	printf("Hello World!\n");
	putc('a', stdout);
	putc('s', stdout);
	printf("\n");
	
	Food food1 = malloc(sizeof(struct food));
	printf("size of food1 = %lu\n", sizeof(food1));
	char *name = "apple";
	food1->name = malloc(strlen(name)+1);
	food1->carb = 13;
	strcpy(food1->name, name);
	
	printf("one serving of %s has %d grams of carb\n", food1->name, food1->carb);
	free(food1->name);
	food1->name = NULL;
	free(food1);
}



