/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:32:00 by enschnei          #+#    #+#             */
/*   Updated: 2025/04/25 16:22:52 by enschnei         ###   ########.fr       */
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

int join_philo(t_philo *philo)
{
	// int i;

	(void) philo;
	// i = 0;
	// while(i < philo->routine.nbr_philos)
	// {
		// if (pthread_join(philo->data[i].thread, NULL))
		// {
		// 	ft_putstr_fd("Error: pthread_join failed\n", 2);
		// 	return (EXIT_FAILURE);
		// }
	// 	i++;
	// }
	// printf("JOIN PHILO\n");
	return (EXIT_SUCCESS);
}

// int destroy_philo(t_philo *philo)
// {
//     int i;

//     i = 0;
//     while (i < philo->routine->nbr_philos)
//     {
//         pthread_mutex_destroy(philo->forks + i);
//       	i++; 
//     }
//     return (EXIT_SUCCESS);
// }

