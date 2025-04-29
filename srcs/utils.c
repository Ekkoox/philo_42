/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:32:00 by enschnei          #+#    #+#             */
/*   Updated: 2025/04/29 15:58:05 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	join_philo(t_philo *philo)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	while (i < philo->routine.nbr_philos)
	{
		if (pthread_join(philo->data[i].thread, NULL))
		{
			ft_putstr_fd("Error: pthread_join failed\n", 2);
			error = 1;
		}
		i++;
	}
	if (error)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_stop_routine(t_philo *philo)
{
	int	state;

	state = 0;
	pthread_mutex_lock(&philo->routine.mutex_over);
	if (philo->routine.stop == 1)
		state = philo->routine.stop;
	pthread_mutex_unlock(&philo->routine.mutex_over);
	return (state);
}
