#include "philosophers.h"

int main(int argc, char **argv)
{
	t_rules			rules;
	t_philosopher	*philosophers;
	pthread_mutex_t	*forks;

	if (argc < 5 || argc > 6)
		return (WRONG_NUM_OF_ARGS);
	rules = parse_arguments(argc, argv);
	print_rules(rules); // debug
	if (!rules.valid)
		return (INVALID_ARGUMENTS);	
	if (init_forks(&forks, rules.number_of_philosophers) == ERROR || 
		init_philosophers(&philosophers, &rules) == ERROR) 
		return (EXIT_FAILURE);
//	print_philos(philosophers, rules.number_of_philosophers); // debug

	threads_join(philosophers, rules.number_of_philosophers);
	free_forks(forks, rules.number_of_philosophers);
	return (EXIT_SUCCESS);
}
