#include "philosophers.h"

void	check_end(t_rules *rules, t_philosopher *philo)
{
	while (rules->synchro == FALSE)
		usleep(1000);
	while (TRUE)
	{
		if (rules->num_must_eat >= 0 && max_eatings_reached(rules, philo))
			break ;
		if (is_one_is_starving(rules, philo))
			break ;
		usleep(1000);
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
	if (max_reached)
		pthread_mutex_lock(&rules->speak);
	return (max_reached);
}

t_bool	is_one_is_starving(t_rules *rules, t_philosopher *philo)
{
	int		i;
	int		eat_timestamp;

	i = -1;
	while (rules->synchro && ++i < rules->num_of_philo)
	{
		eat_timestamp = get_timestamp(philo[i].time_start_last_meal);
		if (eat_timestamp > rules->time_to_die)
		{
			pthread_mutex_lock(&philo->eating);
			print_message("died", &philo[i], LOCK);
			return (TRUE);
		}
	}
	return (FALSE);
}

void	destroy_and_free_mutexes(t_rules *rules, t_philosopher *philos)
{
	int	i;

	i = -1;
	while (++i < rules->num_of_philo)
	{
		pthread_mutex_destroy(&rules->forks[i]);
		pthread_mutex_destroy(&philos[i].eating);
	}
	free(rules->forks);
}
