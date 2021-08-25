#include "philosophers.h"

void print_rules(t_rules rules)
{
	printf("number of philosophers: %d\n", rules.num_of_philo);
	printf("time to die: %d\n", rules.time_to_die);
	printf("time to eat: %d\n", rules.time_to_eat);
	printf("time to sleep: %d\n", rules.time_to_sleep);
	printf("numb of time each philosopher must eat: %d\n",\
			rules.num_must_eat);
	if (rules.valid)
		printf("\tOK\n");
	else
		printf("\tKO\n");
}

void	print_philos(t_philosopher *philos, int num_philos)
{
	int	i;

	i = -1;
	while (++i < num_philos)
		printf("philo number %d\n ", philos[i].index);
}
