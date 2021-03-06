/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argument.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 16:51:59 by aboumadi          #+#    #+#             */
/*   Updated: 2022/05/26 02:56:03 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_data	*get_args(int argc, char **av)
{	
	int		i;
	t_data	*time;

	i = 1;
	while (av[i])
	{
		if (!check_num(av[i]) || ft_atoi(av[i]) <= 0)
			return (NULL);
		i++;
	}
	time = (t_data *)malloc(sizeof (t_data));
	if (argc == 6)
		time->nb_time_to_eat = ft_atoi(av[5]);
	else
	time->nb_time_to_eat = 0;
	time->counter = 0;
	time->die = 0;
	time->n_of_eat = 0;
	time->nb_philo = ft_atoi(av[1]);
	time->time_to_die = ft_atoi(av[2]);
	time->time_to_eat = ft_atoi(av[3]);
	time->time_to_sleep = ft_atoi(av[4]);
	return (time);
}

int	check_num(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && str[i])
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
			i++;
	}
	return (1);
}

int	ft_isdigit(int n)
{
	if (n >= 48 && n <= 57)
		return (1);
	return (0);
}
