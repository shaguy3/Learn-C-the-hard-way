#include <stdio.h>

int main(int argc, char *argv[])
{
	int distance = 100;
	float power = 2.345f;
	double super_power = 56789.4532;
	char initial = 'A';
	char first_name[] = "Guy";
	char last_name[] = "Shamilyan";
	
	printf("You are %d miles from the destination\n\n", distance);
	printf("You have %f levels of power\n\n", power);
	printf("You have %f awesome super powers.\n\n", super_power);
	printf("I have an initial %c.\n\n", initial);
	printf("My first name is %s.\n\n", first_name);
	printf("My last name is %s.\n\n", last_name);
	printf("My full name is %s %c. %s.\n\n", first_name, initial, last_name);
	
	int bugs = 100;
	double bug_rate = 1.2;
	printf("You have %d bugs at the rate of %f.\n", bugs, bug_rate);

	long universe_of_defects = 1L * 1024L * 1024L * 1024L;
	printf("Te univercse has %ld bugs in it.\n", universe_of_defects);
	
	double expected_bugs = bugs * bug_rate;
	printf("You are exoected to have %f bugs\n", expected_bugs);

	double part_of_universe = expected_bugs / universe_of_defects;
	printf("That is only %e portion of the universe.\n", part_of_universe);

	char nul_byte = '\0';
	int care_percentage = bugs * nul_byte;
	printf("Which means you should care %d%%\n\n", care_percentage);
	
	return 0;
}