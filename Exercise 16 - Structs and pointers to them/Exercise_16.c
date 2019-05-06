#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct person {
	char *name;
	int age;
	int height;
	int weight;
};

struct person *person_create(char *name, int age, int height, int weight)
{
	struct person *who = malloc(sizeof(struct person));
	assert(who != NULL);
	
	who->name = strdup(name);
	who->age = age;
	who->height = height;
	who->weight = weight;
	
	return who;
}

void person_destroy(struct person *who)
{
	assert(who != NULL);
	
	free(who->name);
	free(who);
}

void person_print(struct person *who)
{
	printf("Name: %s.\n", who->name);
	printf("Age: %d, Height: %d, Weight: %d.\n",
		who->age, who->height, who->weight);
}

int main(int argc, char *argv[])
{
	// Make two people structures.
	struct person *joe = person_create("Joe", 32, 165, 70);
	struct person *guy = person_create("Guy", 24, 181, 93);
	
	// Print them out and where they are in memory.
	printf("Joe is in memory location %p\n", joe);
	person_print(joe);
	
	printf("Guy is in memory location %p\n", guy);
	person_print(guy);
	
	// Changing the age of the structs.
	joe->age += 20;
	joe->height -= 4;
	person_print(joe);
	
	person_destroy(joe);
	person_destroy(guy);
	
	return 0;
}
