#include "philosophers.h"

int	get_timestamp(const struct timeval origin)
{
	struct timeval	now;
	long			origin_ms;
	long			now_ms;
	int				result;

	gettimeofday(&now, NULL);
	now_ms = now.tv_sec * 1000 + now.tv_usec / 1000;
	origin_ms = origin.tv_sec * 1000 + origin.tv_usec / 1000;
	result = now_ms - origin_ms;
	return (result);
}

void	print_message(const char *msg, t_philosopher *philo)
{
	pthread_mutex_lock(&philo->rules->speak);
	printf("%d philo %d %s\n", 
			get_timestamp(philo->rules->start), philo->index, msg);
//	pthread_mutex_unlock(&philo->rules->speak);

}
