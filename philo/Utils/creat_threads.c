/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:08:12 by aboumadi          #+#    #+#             */
/*   Updated: 2022/04/03 15:09:22 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	creat_threads(t_threads *th, t_time *t, int ac)
{
	int 		i;
	int			nb;
	pthread_t	*th1;

	i = 0;
	nb = t->nb_philo;
	th1 = (pthread_t *)malloc(nb * size(pthread_t));
}