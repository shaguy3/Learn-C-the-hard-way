#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

struct Stack {
	int top;
	unsigned capacity;
	int *array;
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

int Stack_is_empty(struct Stack *my_stack)
{
	return my_stack->top == -1;
}

int Stack_is_full(struct Stack *my_stack)
{
	return my_stack->top == my_stack->capacity - 1;
}

struct Stack* Stack_create(unsigned capacity)
{
	struct Stack *my_stack = (struct Stack *) malloc(sizeof(struct Stack));
	my_stack->capacity = capacity;
	my_stack->array = (int *) malloc(my_stack->capacity * sizeof(int));
	my_stack->top = -1;
	
	return my_stack;
}

int Stack_pop(struct Stack *my_stack)
{
	if (Stack_is_empty(my_stack))
		die("Cannot pop, the stack is empty");
	int num_to_return = my_stack->array[my_stack->top];
	my_stack->top--;
	return num_to_return;
}

void Stack_push(struct Stack *my_stack, int num_to_push)
{
	if (Stack_is_full(my_stack))
		die("Cannot push, the stack is full");
	my_stack->top++;
	my_stack->array[my_stack->top] = num_to_push;
}

void Stack_destroy(struct Stack *my_stack)
{
	if (!my_stack) {
		die("Memory failure - cannot free the stack");
	} else {
		if (my_stack->array)
			free(my_stack->array);
		free(my_stack);
	}
}

int main(int argc, char *argv[])
{
	// Creating the stack.
	struct Stack *my_stack = Stack_create(10);
	
	// Testing operations.
	if (Stack_is_empty(my_stack))
		printf("Right now, the stack is empty\n");
	
	printf("Finished testing stage number 1.\n\n");
		
	Stack_push(my_stack, 20);
	Stack_push(my_stack, 3);
	Stack_push(my_stack, 67);
	Stack_push(my_stack, 1);
	Stack_push(my_stack, 43);
	Stack_push(my_stack, 8324);
	
	int top_number = Stack_pop(my_stack);
	printf("%d just popped out of the stack.\n", top_number);
	
	if (Stack_is_empty(my_stack))
		printf("Right now, the stack is empty\n");
	else if (Stack_is_full(my_stack))
		printf("Right now the stack is full\n");
		
	printf("Finished testing stage number 2.\n\n");
	
	Stack_push(my_stack, 27);
	Stack_push(my_stack, 452);
	Stack_push(my_stack, 627);
	Stack_push(my_stack, 864);
	Stack_push(my_stack, 4325);
	
	if (Stack_is_full(my_stack))
		printf("Right now the stack is full\n");
	
	printf("Finished testing stage number 3.\n\n");
	
	Stack_pop(my_stack);
	Stack_pop(my_stack);
	Stack_pop(my_stack);
	Stack_pop(my_stack);
	Stack_pop(my_stack);
	Stack_pop(my_stack);
	Stack_pop(my_stack);
	Stack_pop(my_stack);
	Stack_pop(my_stack);
	Stack_pop(my_stack);
	
	if (Stack_is_empty(my_stack))
		printf("Right now, the stack is empty\n");
		
	printf("Finished testing! :)\n\n");
	
	
	// Freeing memory.
	Stack_destroy(my_stack);
	
	return 0;
}
