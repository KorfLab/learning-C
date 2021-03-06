#include <stdio.h>
#include <string.h>

// structs are also known as 'objects'
struct person {
	char name[32];
	int age;
};

// typedef lets you rename one variable type into another
// in this case, 'struct person' is renamed 'Person'
typedef struct person Person;

int main () {
	
	struct person i1; // you have to say 'struct'
	strcpy(i1.name, "Ian Korf");
	i1.age = 54;
	printf("%s is %d years old\n", i1.name, i1.age);
	
	Person i2; // typedef is a little tidier without saying 'struct'
	strcpy(i2.name, "Joe Shmoe");
	i2.age = 25;
	printf("%s is %d years old\n", i2.name, i2.age);
	
	Person i3;
	strcpy(i3.name, "Alan Zhang");
	//i3.name = "Alan Zhang"; 
	i3.age = 21;
	printf("%s is %d years old\n", i3.name, i3.age);
	// how big is a struct?
	printf("%d %d %d\n", (int)sizeof(Person), (int)sizeof(i2), (int)sizeof(i1));
	
	Person i4;
	printf("%s is %d years old\n", i4.name, i4.age); // uninitialized...
}
