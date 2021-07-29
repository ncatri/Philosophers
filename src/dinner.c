#include "philosophers.h"

void	*dinner(void *philosopher)
{
	printf("I am philosopher %d\n", ((t_philosopher*)philosopher)->index);
	// eat();
	// sleep();
	// think();
	
	return (NULL);
}
