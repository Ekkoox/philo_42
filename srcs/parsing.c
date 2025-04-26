/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:32:14 by enschnei          #+#    #+#             */
/*   Updated: 2025/04/25 15:32:14 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_whitiespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\r'
		|| c == '\n' || c == '\v' || c == '\f')
		return (0);
	return (1);
}

static int	is_digit(char *str)
{
	int	i;

	i = 0;
	while (is_whitiespace(str[i]) == 0)
		i++;
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (ft_putstr_fd(ERR_PAR_NODIGIT, 2), 1);
		i++;
	}
	return (0);
}

int	convert_nbr(char *str)
{
	long int	nbr;
	int			i;

	i = 0;
	nbr = 0;
	if (is_digit(str) == 1)
		return (-1);
	while (str[i])
	{
		nbr = (nbr * 10) + (str[i] - 48);
		if (nbr > INT_MAX)
			return (ft_putstr_fd(ERR_PAR_OUTRANGE, 2), -1);
		i++;
	}
	return ((int)nbr);
}

int	check_parsing(t_philo *philo, int ac)
{
	(void)ac;
	if (philo->routine.nbr_philos == -1
		|| philo->routine.time_to_die == -1
		|| philo->routine.time_to_eat == -1
		|| philo->routine.time_to_sleep == -1)
		return (EXIT_FAILURE);
	// if (ac == 6 && philo->routine.meals_count == -1)
	// 	return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
