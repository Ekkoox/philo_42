#include "philo.h"

int	main(int ac, char **av)
{
	t_philo	*philo;

	(void)ac;
	philo = NULL;
	if (ac < 5 || ac > 6)
	{
		ft_putstr_fd("Error: Invalid number of arguments\n", 2);
		return (EXIT_FAILURE);
	}
	if (init_struct(&philo) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (init(philo, ac, av) == EXIT_FAILURE)
	{
		free_struct(philo);
		return (EXIT_FAILURE);
	}
	printf("Number of philosophers = %d\n", philo->routine->nbr_philos);
    printf("Die = %d\n", philo->routine->time_to_die);
    printf("Eat = %d\n", philo->routine->time_to_eat);
    printf("Sleep = %d\n", philo->routine->time_to_sleep);
	printf("Meals = %d\n", philo->routine->meals_count);
	join_philo(philo);
	free_struct(philo);
	return (EXIT_SUCCESS);
}
