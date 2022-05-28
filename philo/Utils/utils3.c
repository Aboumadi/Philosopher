/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:29:43 by aboumadi          #+#    #+#             */
/*   Updated: 2022/05/23 22:47:45 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long long	current_time(void)
{
	struct timeval	time;
	long long		time_mil;

	gettimeofday(&time, NULL);
	time_mil = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (time_mil);
}

void	ft_print(t_data *philo, int id, char *str)
{
	pthread_mutex_lock(&philo->print);
	if (philo->die == 0)
		printf("%lld	%d		%s\n", (current_time() - philo->start_time),
			id + 1, str);
	pthread_mutex_unlock(&philo->print);
}
