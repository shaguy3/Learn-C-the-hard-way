#include <stdio.h>

int main(int argc, char *argv[])
{
	// Create to arrays we care about.
	int ages[] = { 23, 43, 12, 89, 2 };
	char *names[] = { "Alan", "Frank", "Mary", "John", "Lisa" };
	
	// Safely get the size of ages.
	int count = sizeof(ages) / sizeof(int);
	int i = 0;
	
	// first way of using indexing.
	for (i = 0; i < count; i++) {
		printf("%s has lived for %d years.\n", names[i], ages[i]);
	}
	
	printf("---------\n");
	
	// Set up the pointers to the start of the arrays.
	int *cur_age = ages;
	char **cur_name = names;
	
	// Second way using pointers.
	for (i = 0; i < count; i++) {
		printf("%s is %d years old.\n",
			*(cur_name + i), *(cur_age + i));
	}
	
	printf("---------\n");
	
	// Third way, pointers are just arrays.
	for (i = 0; i < count; i++) {
		printf("%s has evaded death for %d years.\n", 
			cur_name[i], cur_age[i]);
	}
	
	printf("---------\n");
	
	// Forth way with pointers in a stupid complex way.
	for (cur_name = names, cur_age = ages; 
			(cur_age - ages) < count; cur_name ++, cur_age++) {
		printf("%s had %d birthdays.\n", *cur_name, *cur_age);
	}
	
	printf("---------\n");
	
	// Testing the & syntax.
	cur_name = names;
	
	for (i = 0; i < count; i ++) {
		printf("The address of %s is %p\n", cur_name[i], &cur_name[i]);
	}
	
	return 0;
}
