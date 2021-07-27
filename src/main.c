#include "philosophers.h"

int main(int argc, char **argv)
{
	t_rules	rules;

	if (argc < 5 || argc > 6)
		return (WRONG_NUM_OF_ARGS);
	rules = parse_arguments(argc, argv);	
	if (!rules.valid)
		return (INVALID_ARGUMENTS);	
	return (EXIT_SUCCESS);
}
