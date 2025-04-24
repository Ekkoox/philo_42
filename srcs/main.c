#include "philo.h"

int	main(int ac, char **av)
{
	t_philo	*philo;

	(void)ac;
	philo = NULL;
	check_args(ac, av);
	// if (init_struct(&philo) == EXIT_FAILURE)
	// 	return (EXIT_FAILURE);
	// init
	// philo->routine->nbr_philos = atoi(av[1]);
	// printf("Number of philosophers: %d\n", philo->routine->nbr_philos);
	// join_philo(philo);
	// free_struct(philo);
	return (EXIT_SUCCESS);
}
