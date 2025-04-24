# include "philo.h"

// void	destroy_mutex(t_philo *philo)
// {
// 	if (&philo->routine->stop_mutex == 1)
// 		pthread_mutex_destroy(&philo->routine->stop_mutex);
// 	if (&philo->routine->meals_mutex == 2)
// 		pthread_mutex_destroy(&philo->routine->meals_mutex);
// 	if (&philo->data->left_forks == 3)
// 		pthread_mutex_destroy(&philo->data->left_forks);
// 	if (&philo->data->right_forks == 4)
// 		pthread_mutex_destroy(&philo->data->right_forks);
// }

// int	check_philo(t_philo *philo)
// {
// 	pthread_mutex_lock(&philo);
// }
//check si manager a um philo mort, si oui exit les autres
