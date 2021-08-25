#include "philosophers.h"

int main(int argc, char **argv)
{
	t_rules			rules;
	t_philosopher	*philosophers;

	rules = parse_arguments(argc, argv);
	if (!rules.valid)
		return (INVALID_ARGUMENTS);	
	if (start_dinner(&rules, &philosophers) == ERROR)
		return (EXIT_FAILURE);
	check_end(&rules, philosophers);
	free_forks(rules.forks, rules.num_of_philo);
	free(philosophers);
	return (EXIT_SUCCESS);
}
