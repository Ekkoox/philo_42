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
