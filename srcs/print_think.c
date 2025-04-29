/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:07:20 by enschnei          #+#    #+#             */
/*   Updated: 2025/04/29 15:31:38 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_think(t_data *data)
{
	can_i_print(data, THINK);
	return (EXIT_SUCCESS);
}
