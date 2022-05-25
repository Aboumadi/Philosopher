/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 00:53:49 by aboumadi          #+#    #+#             */
/*   Updated: 2022/05/23 22:58:51 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ready_to_eat(t_data *data, t_th *philo)
{
	long	nw_time;

	pthread_mutex_lock(&(data->eat));
	ft_print(data, philo->id, "is eating");
	philo->check_die = current_time();
	pthread_mutex_unlock(&(data->eat));
	(philo->nb_of_eat)++;
	nw_time = current_time();
	while (current_time() - nw_time < data->time_to_eat)
		usleep(100);
}

int	ready_to_taking_forks(t_data *data, t_th *philo)
{
	pthread_mutex_lock(&(data->fork[philo->fork_left]));
	ft_print(data, philo->id, "has taken fork");
	pthread_mutex_lock(&(data->fork[philo->fork_right]));
	ft_print(data, philo->id, "has taken fork");
	ready_to_eat(data, philo);
	pthread_mutex_unlock(&(data->fork[philo->fork_left]));
	pthread_mutex_unlock(&(data->fork[philo->fork_right]));
	if (data->n_of_eat)
		return (1);
	return (0);
}

void	*routine(void *philo)
{
	t_th	*c_philo;
	t_data	*c_data;
	long	new_time2;

	c_philo = (t_th *) philo;
	c_data = c_philo->philo;
	if (c_data->nb_philo == 1)
	{
		ft_print(c_data, c_philo->id, "has taken fork\n");
		usleep(c_data->time_to_die * 1000);
		return (NULL);
	}
	if (c_philo->id % 2)
		usleep(1000);
	while (!c_data->die)
	{
		if (ready_to_taking_forks(c_data, c_philo))
			break ;
		ft_print(c_data, c_philo->id, "is sleeping");
		new_time2 = current_time();
		while (current_time() - new_time2 < c_data->time_to_sleep)
			usleep(100);
		ft_print(c_data, c_philo->id, "is thinking");
	}
	return (NULL);
}
