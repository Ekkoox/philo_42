/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:32:16 by enschnei          #+#    #+#             */
/*   Updated: 2025/04/25 19:02:20 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo	philo;

	memset(&philo, 0, sizeof(t_philo));
	if (ac < 5 || ac > 6)
	{
		ft_putstr_fd("Error: Invalid number of arguments\n", 2);
		return (EXIT_FAILURE);
	}
	if (init(&philo, ac, av) == EXIT_FAILURE)
		return (free_struct(&philo), EXIT_FAILURE);
	if (routine(&philo) == EXIT_FAILURE)
		return (free_struct(&philo), EXIT_FAILURE);
	if (join_philo(&philo) == EXIT_FAILURE)
		return (free_struct(&philo), EXIT_FAILURE);
	free_struct(&philo);
	return (EXIT_SUCCESS);
}
