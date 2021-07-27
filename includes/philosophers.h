#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

typedef int t_bool;
# define TRUE (1);
# define FALSE (0);

enum e_errors
{
	WRONG_NUM_OF_ARGS = 1;
	INVALID_ARGUMENTS = 2;
};

typedef struct s_rules
{
	int numbers_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	t_bool	valid;
}				t_rules;

t_rules	parse_arguments(int argc, char **argv);
