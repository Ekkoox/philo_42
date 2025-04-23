#include "philo.h"

int	main(void)
{
	t_philo *philo;

	philo = ft_calloc(sizeof(t_philo), 1);
	if (!philo)
	{
		printf("Error: Memory allocation failed\n");
		return (1);
	}
	free(philo);
	return (0);
}