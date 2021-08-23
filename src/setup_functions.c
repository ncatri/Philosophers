#include "philosophers.h"

t_error	start_dinner(t_rules *rules, t_philosopher **philo, pthread_mutex_t **forks)
{
	gettimeofday(&rules->start, NULL);
	if (init_forks(forks, rules->number_of_philosophers) == ERROR)
		return (ERROR);
	if (init_philosophers(philo, rules) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

t_error	init_philosophers(t_philosopher **philo, t_rules *rules)
{
	int	i;

	if (!philo)
		return (ERROR);
	*philo = malloc(sizeof(t_philosopher) * rules->number_of_philosophers);
	if (*philo == NULL)
		return (ERROR);
	i = -1;
	while (++i < rules->number_of_philosophers)
	{
		(*philo)[i].index = i + 1;
		(*philo)[i].time_start_last_meal = 0;
		(*philo)[i].rules = rules;
		if (pthread_create(&(*philo)[i].thread_id, NULL, dinner, &(*philo)[i]) != 0)
			return (ERROR);
//		pthread_join((*philo)[i].thread_id, NULL);
	}
	return (SUCCESS);
}

t_error	init_forks(pthread_mutex_t **forks, int num_of_philo)
{
	int i;
	int	err_check;

	if (!forks)
		return (ERROR);
	*forks = malloc(sizeof(pthread_mutex_t) * num_of_philo);
	if (!*forks)
		return (ERROR);
	i = -1;
	while (++i < num_of_philo)
	{
		err_check = pthread_mutex_init(*forks + i, NULL);
		if (err_check != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(*forks + i);
			return (ERROR);
		}
	}
	return (SUCCESS);
}

void	free_forks(pthread_mutex_t *forks, int num_of_philo)
{
	int i;

	i = -1;
	while (++i < num_of_philo)
		pthread_mutex_destroy(forks + i);
	free(forks);
}

void	threads_join(t_philosopher *philosophers, int num_of_philo)
{
	int	i;

	i = -1;
	while (++i < num_of_philo)
		pthread_join(philosophers[i].thread_id, NULL);
}
