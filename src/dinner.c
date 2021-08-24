#include "philosophers.h"

void	*dinner(void *philosopher)
{
	t_philosopher	*philo;

	philo = (t_philosopher*)philosopher;
	while (philo->rules->synchro == FALSE)
		usleep(1000);
	if (philo->index % 2 == 0)
		usleep(1000);
	eat(philo);
	// sleep();
	// think();
	
	return (NULL);
}

void	eat(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->rules->forks[philo->index - 1]);
	print_message("has taken a fork", philo);
	pthread_mutex_lock(&philo->rules->forks[(philo->index  % philo->rules->number_of_philosophers)]);
	print_message("has taken a fork", philo);
	print_message("is eating", philo);

	usleep(philo->rules->time_to_eat);
	
	pthread_mutex_unlock(&philo->rules->forks[philo->index - 1]);
	print_message("has dropped a fork", philo);
	pthread_mutex_unlock(&philo->rules->forks[(philo->index  % philo->rules->number_of_philosophers)]);
	print_message("has dropped a fork", philo);
}
