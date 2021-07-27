#include "philosophers.h"

t_error	init_philosophers(t_philosopher **philo, int num_of_philo)
{
	int	i;

	if (!philo)
		return (ERROR);
	*philo = malloc(sizeof(t_philosopher) * num_of_philo);
	if (*philo == NULL)
		return (ERROR);
	i = -1;
	while (++i < num_of_philo)
	{
		(*philo)[i].index = i + 1;
		(*philo)[i].time_start_last_meal = 0;
	}
	return (SUCCESS);
}
