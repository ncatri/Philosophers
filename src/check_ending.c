#include "philosophers.h"

void	check_end(t_rules *rules, t_philosopher *philo)
{
	while (rules->synchro == FALSE)
		usleep(1000);
	while (TRUE)
	{
		if (rules->num_must_eat >= 0 && max_eatings_reached(rules, philo))
			break;
	}
}

t_bool	max_eatings_reached(t_rules *rules, t_philosopher *philo)
{
	int		i;
	t_bool	max_reached;

	max_reached = TRUE;
	i = -1;
	while (++i < rules->num_of_philo && max_reached == TRUE)
	{
		if (philo[i].num_of_eats < rules->num_must_eat)
			max_reached = FALSE;
	}
	return (max_reached);
}
