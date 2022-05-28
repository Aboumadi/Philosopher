/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:29:48 by aboumadi          #+#    #+#             */
/*   Updated: 2022/05/26 02:36:32 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	how_mutch_eat(t_data *data, t_th *ph)
{
	int	i;

	i = 0;
	while (i < data->nb_philo && ph->nb_of_eat > 0
		&& ph[i].nb_of_eat >= data->nb_time_to_eat)
		i++;
	if (i == data->nb_philo)
		data->n_of_eat = 1;
}

void	ft_check_death(t_data *data, t_th *philo)
{
	int		i;

	while (!data->n_of_eat)
	{
		i = 0;
		while ((i < data->nb_philo) && (!data->die))
		{
			pthread_mutex_lock(&(data->eat));
			if ((current_time() - philo[i].check_die) > data->time_to_die)
			{
				ft_print(data, philo->id, "is death");
				data->die = 1;
			}
			pthread_mutex_unlock(&(data->eat));
			i++;
		}
		if (data->die)
			break ;
		if (data->nb_time_to_eat > 0)
			how_mutch_eat(data, philo);
	}
}

void	ending(t_data *philo)
{
	int	i;

	i = 0;
	while (i < philo->nb_philo)
		pthread_join(philo->data_of_philo[i++].ph, NULL);
	i = 0;
	while (i < philo->nb_philo)
		pthread_mutex_destroy(&(philo->fork[i++]));
	pthread_mutex_destroy(&(philo->eat));
	pthread_mutex_destroy(&(philo->print));
	pthread_mutex_destroy(&(philo->death));
	free(philo->fork);
	free(philo->data_of_philo);
	free(philo);
}

int	creat_thread(t_data *philo, t_th *ph)
{
	int	i;

	i = 0;
	philo->start_time = current_time();
	while (i < philo->nb_philo)
	{
		philo->data_of_philo[i].check_die = current_time();
		if (pthread_create(&philo->data_of_philo[i].ph,
				NULL, routine, (void *) &ph[i]))
		{
			printf("error in creat th\n");
			return (1);
		}
		i++;
	}
	ft_check_death(philo, ph);
	ending(philo);
	return (0);
}
