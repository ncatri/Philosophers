#include "philosophers.h"

void	*dinner(void *philosopher)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)philosopher;
	while (philo->rules->synchro == FALSE)
		usleep(1000);
	if (philo->index % 2 == 0)
		usleep(1000);
	while (TRUE)
	{
		eating(philo);
		sleeping_and_thinking(philo);
	}
	return (NULL);
}

void	eating(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->rules->forks[philo->index - 1]);
	print_message("has taken a fork", philo, UNLOCK);
	pthread_mutex_lock(\
			&philo->rules->forks[(philo->index % philo->rules->num_of_philo)]);
	print_message("has taken a fork", philo, UNLOCK);
	print_message("is eating", philo, UNLOCK);
	pthread_mutex_lock(&philo->eating);
	gettimeofday(&philo->time_start_last_meal, NULL);
	philo->num_of_eats++;
	pthread_mutex_unlock(&philo->eating);
	my_usleep(philo->rules->time_to_eat);
	pthread_mutex_unlock(&philo->rules->forks[philo->index - 1]);
	pthread_mutex_unlock(\
			&philo->rules->forks[(philo->index % philo->rules->num_of_philo)]);
}

void	sleeping_and_thinking(t_philosopher *philo)
{
	print_message("is sleeping", philo, UNLOCK);
	my_usleep(philo->rules->time_to_sleep);
	print_message("is thinking", philo, UNLOCK);
}
