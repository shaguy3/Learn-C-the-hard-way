#include <stdio.h>

int main(int argc, char *argv[])
{
	int areas[] = { 10, 12, 13, 14, 20 };
	char name[] = "Guy";
	char full_name[] = { 'G', 'u', 'y', ' ', 'A', '.', ' ',
		'S', 'h', 'a', 'm', 'i', 'l', 'y', 'a', 'n', '\0' };
	
	printf("The size of an int is: %ld\n", sizeof(int));
	printf("The size of areas (int[]): %ld\n", sizeof(areas));
	printf("The number of ints in areas: %ld\n",
		sizeof(areas) / sizeof(int));
	printf("The first area is: %d. The second is %d.\n\n",
		areas[0], areas[1]);
	
	printf("The size of a char is: %ld\n", sizeof(char));
	printf("The size of name is: %ld\n", sizeof(name));
	printf("The number of chars in name is: %ld\n\n",
		sizeof(name) / sizeof(char));
	
	printf("The size of full_name is: %ld\n",
		sizeof(full_name));
	printf("The number of chars: %ld\n",
		sizeof(full_name) / sizeof(char));
	printf("name=\"%s\" and full_name=\"%s\"\n",
		name, full_name);
	
	return 0;
}
