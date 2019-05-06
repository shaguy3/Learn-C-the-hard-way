#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

struct Stack {
	FILE *file;
	int rows[10];
	int *cur_row;
};

void die(const char *message)
{
	if (errno) {
		perror(message);
	} else {
		printf("ERROR: %s\n", message);
	}
	
	exit(1);
}

struct Stack Stack_open()
{
	struct Stack *my_stack = malloc(sizeof(struct Stack));
	if (!my_stack)
		die("Memory error");
	my_stack->cur_row = my_stack->rows[0];
	
	return *my_stack;
}

int pop(struct Stack *my_stack)
{
	
}

void insert(struct Stack *my_stack, int num_to_insert)
{
	
}

void show_all()
{

}

void Stack_destroy(struct Stack *my_stack)
{

}

int main(int argc, char *argv[])
{
	if (argc < 3)
		die("Wrong usage. stack <filename> <action> <action params>");
		
	char action = argv[2][0];
	char *filename = argv[1];
	
	
}




















