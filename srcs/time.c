/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:32:05 by enschnei          #+#    #+#             */
/*   Updated: 2025/04/25 15:32:05 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned int get_time()
{
    struct timeval time;
    
    if(gettimeofday(&time, NULL) == -1)
    {
        perror("Error time receive");
        exit(EXIT_FAILURE);
    }
    return (((time.tv_sec) * 1000) + (time.tv_usec / 1000));
}
