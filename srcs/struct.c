/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:32:08 by enschnei          #+#    #+#             */
/*   Updated: 2025/04/25 16:21:48 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_struct(t_philo *philo)
{
	memset(philo, 0, sizeof(t_philo));
	return (EXIT_SUCCESS);
}

void	free_struct(t_philo *philo)
{
	if (philo->data)
		free(philo->data);
	// free(philo);
}
