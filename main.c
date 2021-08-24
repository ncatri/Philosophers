#include "philosophers.h"

int main(int argc, char **argv)
{
	t_rules			rules;
	t_philosopher	*philosophers;

	rules = parse_arguments(argc, argv);
	if (!rules.valid)
		return (INVALID_ARGUMENTS);	
	start_dinner(&rules, &philosophers);
	//print_philos(philosophers, rules.number_of_philosophers); // debug

	//threads_join(philosophers, rules);
	check_end(&rules, philosophers);
	free_forks(rules.forks, rules.num_of_philo);
	free(philosophers);
	return (EXIT_SUCCESS);
}
