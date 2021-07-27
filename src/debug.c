#include "philosophers.h"

void print_rules(t_rules rules)
{
	printf("number of philosophers: %d\n", rules.number_of_philosophers);
	printf("time to die: %d\n", rules.time_to_die);
	printf("time to eat: %d\n", rules.time_to_eat);
	printf("time to sleep: %d\n", rules.time_to_sleep);
	printf("numb of time each philosopher must eat: %d\n",\
			rules.number_of_times_each_philosopher_must_eat);
	if (rules.valid)
		printf("\tOK\n");
	else
		printf("\tKO\n");
}
