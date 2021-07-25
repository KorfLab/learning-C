#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void hello_world(void) {
	printf("hello world\n");
}

void hello(void){
	for(int i = 0; i < 5; i++){
		printf("Hello!\n");
	}
}
