/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enschnei <enschnei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:32:10 by enschnei          #+#    #+#             */
/*   Updated: 2025/04/25 18:02:16 by enschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int check_death(t_routine *routine)
{
    int state;

    state = 0;
    pthread_mutex_lock(&routine->mutex_over);
    if (routine->stop == 1)
        state = routine->stop;
    pthread_mutex_unlock(&routine->mutex_over);
    return (state);
}

static void	*routine_philo(void *arg)
{
    t_philo	*philo;

    philo = (t_philo *)arg;
    if (philo->data->id % 2 == 0)
        usleep(1000);
    while (check_death(&philo->routine) != 0)
    {
        if (print_eat(philo) == EXIT_FAILURE)
            return (NULL);
        if (print_sleep(philo) == EXIT_FAILURE)
            return (NULL);
        if (print_think(philo) == EXIT_FAILURE)
            return (NULL);
    }
    return (NULL);
}

int    routine(t_philo *philo)
{
    int	i;
    // pthread_t monitor;

    i = 0;
    philo->routine.start_time = get_time();
    philo->routine.stop = 0;
    while (i < philo->routine.nbr_philos)
    {
        if (pthread_create(&philo->data[i].thread, NULL, routine_philo, &philo[i]) != 0)
        {
            ft_putstr_fd("Error: Thread creation failed\n", 2);
            return (EXIT_FAILURE);
        }
        i++;
    }
    // pthread_create(&monitor, NULL, monitor_philo, philo);
    return (EXIT_SUCCESS);
}
