#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 0;
	
	for (i = 1; i < argc; i++) {
		printf("arg %d: %s\n", i, argv[i]);
	}
	char *cities[] = { "Kfar sava", "Hod hasharon", "Ashahei Rachel",
		"Hadera" };
	
	int j = 0;
	int number_of_cities = sizeof(cities) / 8;
	while (j < number_of_cities) {
		printf("City %d: %s\n", j, cities[j]);
		j++;
	}
	
	return 0;
}
