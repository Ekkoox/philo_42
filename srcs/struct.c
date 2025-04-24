#include "philo.h"

int	init_struct(t_philo **philo)
{
	*philo = ft_calloc(sizeof(t_philo), 1);
	if (!philo)
	{
		ft_putstr_fd("Error: Philo memory allocation failed\n", 2);
		return (EXIT_FAILURE);
	}
	(*philo)->data = ft_calloc(sizeof(t_routine), 1);
	if (!(*philo)->data)
	{
		ft_putstr_fd("Error: Data memory allocation failed\n", 2);
		free(*philo);
		return (EXIT_FAILURE);
	}
	(*philo)->routine = ft_calloc(sizeof(t_routine), 1);
	if (!(*philo)->routine)
	{
		ft_putstr_fd("Error: Routine memory allocation failed\n", 2);
		free((*philo)->data);
		free(*philo);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	free_struct(t_philo *philo)
{
	if (philo->data)
		free(philo->data);
	if (philo->routine)
		free(philo->routine);
	free(philo);
}
