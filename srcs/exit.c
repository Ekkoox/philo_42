# include "philo.h"

// void	destroy_mutex(t_philo *phill)
// {
// 	if (&phill->routine->stop_mutex == 1)
// 		pthread_mutex_destroy(&phill->routine->stop_mutex);
// 	if (&phill->routine->meals_mutex == 2)
// 		pthread_mutex_destroy(&phill->routine->meals_mutex);
// 	if (&phill->data->left_forks == 3)
// 		pthread_mutex_destroy(&phill->data->left_forks);
// 	if (&phill->data->right_forks == 4)
// 		pthread_mutex_destroy(&phill->data->right_forks);
// }

// int	check_philo(t_philo *phill)
// {
// 	pthread_mutex_lock(&phill);
// }
//check si manager a um philo mort, si oui exit les autres
// 