#include "philosophers.h"

t_rules	parse_arguments(int argc, char **argv)
{
	t_rules	rules;
	int		i;

	i = 1;
	while (i < argc)
		printf("%s\n", argv[i]);
	rules.valid = TRUE;
	return rules;
}
