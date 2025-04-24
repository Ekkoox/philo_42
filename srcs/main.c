#include "philo.h"

int	main(int ac, char **av)
{
	t_philo	*philo;

	philo = NULL;
	if (ac < 5 || ac > 6)
	{
		ft_putstr_fd("Error: Invalid number of arguments\n", 2);
		return (EXIT_FAILURE);
	}
	if (init_struct(&philo) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (init(philo, ac, av) == EXIT_FAILURE)
		return (free_struct(philo), EXIT_FAILURE);
	if (join_philo(philo) == EXIT_FAILURE)
		return (free_struct(philo), EXIT_FAILURE);
	free_struct(philo);
	return (EXIT_SUCCESS);
}
