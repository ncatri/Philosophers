#include "philosophers.h"

void	*dinner(void *philosopher)
{
	t_philosopher	*philo;

	philo = (t_philosopher*)philosopher;
	while (philo->rules->synchro == FALSE)
		usleep(1000);
	if (philo->index % 2 == 0)
		usleep(1000);
	while (TRUE)
	{
		eating(philo);
		sleeping(philo);
	}
	
	return (NULL);
}

void	eating(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->rules->forks[philo->index - 1]);
	print_message("has taken a fork", philo);
	pthread_mutex_lock(&philo->rules->forks[(philo->index  % philo->rules->num_of_philo)]);
	print_message("has taken a fork", philo);
	print_message("is eating", philo);
	philo->num_of_eats++;

	my_usleep(philo->rules->time_to_eat);
	
	pthread_mutex_unlock(&philo->rules->forks[philo->index - 1]);
	print_message("has dropped a fork", philo);
	pthread_mutex_unlock(&philo->rules->forks[(philo->index  % philo->rules->num_of_philo)]);
	print_message("has dropped a fork", philo);
}

void	sleeping(t_philosopher *philo)
{
	print_message("is sleeping", philo);
	my_usleep(philo->rules->time_to_sleep);
}
/*
void	check_end(t_rules rules, t_philosopher *philo)
{
	int	i;

	while (rules.synchro == FALSE)
		usleep(1000);
	while (TRUE)
	{
		if (max_eatings_reached(rules, philo))
			break;
	}
}
*/
