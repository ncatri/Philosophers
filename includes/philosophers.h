#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

typedef int t_bool;
# define TRUE (1)
# define FALSE (0)

# define INVALID_NUMBER (-1)

enum e_errors
{
	WRONG_NUM_OF_ARGS = 1,
	INVALID_ARGUMENTS = 2,
};

typedef struct s_rules
{
	int number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
	t_bool	valid;
}				t_rules;

typedef struct s_philospher
{
	int number;
	int time_start_last_meal;
}

typedef int	t_fork;

/* parsing */

t_rules	parse_arguments(int argc, char **argv);
int		get_number(char *str);
void	check_validity(t_rules *rules, int argc);

/* parsing utils */

int	ft_atoi(const char *nptr);
t_bool	ft_isdigit(int c);

/* debug */

void	print_rules(t_rules rules);

#endif
