#include "philosophers.h"

t_rules	parse_arguments(int argc, char **argv)
{
	t_rules	rules;

	if (argc < 5 || argc > 6)
	{
		rules.valid = FALSE;
		return (rules);
	}
	rules.num_of_philo= get_number(argv[1]);
	rules.time_to_die = get_number(argv[2]);
	rules.time_to_eat = get_number(argv[3]);
	rules.time_to_sleep = get_number(argv[4]);
	rules.synchro = FALSE;
	if (argc == 6)
		rules.num_must_eat = get_number(argv[5]);
	check_validity(&rules, argc);
	return (rules);
}

int	get_number(char *str)
{
	int		number;
	char	*tmp;

	tmp = str;
	if (*str == '-')
		return (INVALID_NUMBER);
	while (*tmp)
	{
		if (!ft_isdigit(*tmp))
			return (INVALID_NUMBER);
		tmp++;
	}
	number = ft_atoi(str);
	return (number);
}

void	check_validity(t_rules *rules, int argc)
{
	if (rules->num_of_philo < 0 ||
			rules->time_to_die < 0 ||
			rules->time_to_eat < 0 ||
			rules->time_to_sleep < 0)
		rules->valid = FALSE;
	else
		rules->valid = TRUE;
	if (argc == 6 && rules->num_must_eat < 0)
		rules->valid = FALSE;
	else if (argc == 5)
		rules->num_must_eat = -1;
}
