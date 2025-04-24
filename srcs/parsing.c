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

static int	convert_nbr(char *str)
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
