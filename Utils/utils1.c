/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:29:52 by aboumadi          #+#    #+#             */
/*   Updated: 2022/05/23 22:47:40 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	initialisation(t_data *philo)
{
	if (initialisation_mutex(philo) == 1 || initialisation_philo(philo) == 1)
		return (1);
	return (0);
}

int	initialisation_mutex(t_data *philo)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&philo->eat, NULL))
		return (1);
	if (pthread_mutex_init(&philo->print, NULL))
		return (1);
	if (pthread_mutex_init(&(philo)->death, NULL))
		return (1);
	philo->fork = malloc(sizeof (pthread_mutex_t) * philo->nb_philo);
	if (!philo->fork)
		return (1);
	while (i < philo->nb_philo)
	{
		if (pthread_mutex_init(&philo->fork[i], NULL))
			return (1);
		i++;
	}
	return (0);
}

int	initialisation_philo(t_data *philo)
{
	int	i;

	i = 0;
	philo->data_of_philo = malloc(sizeof (t_data) * philo->nb_philo);
	if (!philo->data_of_philo)
		return (1);
	while (i < philo->nb_philo)
	{
		philo->data_of_philo[i].id = i;
		philo->data_of_philo[i].fork_left = i;
		philo->data_of_philo[i].fork_right = (i + 1) % philo->nb_philo;
		philo->data_of_philo[i].philo = philo;
		philo->data_of_philo[i].check_die = 0;
		philo->data_of_philo[i].nb_of_eat = 0;
		i++;
	}
	return (0);
}
