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

void	my_usleep(int target)
{
	int				time;
	struct timeval	tmp;

	gettimeofday(&tmp, NULL);
	time = 0;
	while (time < target)
	{
		usleep(20);
		time = get_timestamp(tmp);
	}
}

void	print_message(const char *msg, t_philosopher *philo, t_bool lock)
{
	pthread_mutex_lock(&philo->rules->speak);
	printf("%d philo %d %s\n", \
			get_timestamp(philo->rules->start), philo->index, msg);
	if (lock == UNLOCK)
		pthread_mutex_unlock(&philo->rules->speak);
}
