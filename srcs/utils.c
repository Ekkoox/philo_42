#include "philo.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int join_philo(t_philo *philo)
{
	// int i;

	// i = 0;
	// while(i < philo->philosophers)
	// {
	// 	pthread_join(philo[i].thread, NULL);
	// 	i++;
	// }
	return (EXIT_SUCCESS);
}
