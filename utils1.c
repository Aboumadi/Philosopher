/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:29:52 by aboumadi          #+#    #+#             */
/*   Updated: 2022/04/17 01:08:58 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
int	ft_work1(t_data *time, t_th **ph)
{
	int	i;

	i = 0;
}
int	get_th(t_data *time, t_th **ph)
{
	int	i;

	i = 0;
	*ph = malloc(sizeof(t_th) * time->nb_philo);
	if (!ph)
	{
		printf("error in allocation\n");
		return (0);
	}
	while (i++ < time->nb_philo)
	{
		if (!pthread_mutex_init(&(*ph[i].mut_fork_right), NULL));
		{
			printf("error in mutex right\n");
			return (0);
		}
		if (!pthread_mutex_init(&(*ph[i].mut_fork_left), NULL));
		{
			printf("error in mutex left\n");
			return (0);
		}
	}
	if(!ft_work1(time, ph));
		return (0);
	return (1);
}