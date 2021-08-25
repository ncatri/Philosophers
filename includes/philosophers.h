#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef int	t_bool;
# define TRUE (1)
# define FALSE (0)

# define INVALID_NUMBER (-1)
# define LOCK (0)
# define UNLOCK (1)

typedef int	t_error;

enum e_errors
{
	SUCCESS,
	WRONG_NUM_OF_ARGS,
	INVALID_ARGUMENTS,
	ERROR,
};

typedef struct s_rules
{
	int	num_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_must_eat;
	
	pthread_mutex_t	*forks;
	struct timeval	start;
	pthread_mutex_t speak;
	t_bool			synchro;
	t_bool			valid;
}				t_rules;

typedef struct s_philosopher
{
	int				index;
	pthread_t		thread_id;
	struct timeval	time_start_last_meal;
	int				num_of_eats;
	pthread_mutex_t	eating;
	t_rules			*rules;
}				t_philosopher;

/* parsing */

t_rules	parse_arguments(int argc, char **argv);
int		get_number(char *str);
void	check_validity(t_rules *rules, int argc);

/* parsing utils */

int		ft_atoi(const char *nptr);
t_bool	ft_isdigit(int c);

/* debug */

void	print_rules(t_rules rules);
void	print_philos(t_philosopher *philos, int num_of_philos);

/* philosophers */

t_error	start_dinner(t_rules *rules, t_philosopher **philo);
t_error	init_philosophers(t_philosopher **philo, t_rules *rules);
t_error	init_mutexes(t_rules *rules);
void	free_forks(pthread_mutex_t *forks, int num_of_philo);

void	*dinner(void *philosopher);
void	eating(t_philosopher *philo);
void	sleeping(t_philosopher *philo);

/* utils */

int		get_timestamp(const struct timeval origin);
void	print_message(const char *msg, t_philosopher *philo, t_bool lock);
void	my_usleep(int target);

/* check_ending */

void	check_end(t_rules *rules, t_philosopher *philo);
t_bool	max_eatings_reached(t_rules *rules, t_philosopher *philo);
t_bool	is_one_is_starving(t_rules *rules, t_philosopher *philo);

#endif
