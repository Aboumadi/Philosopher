/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 22:45:47 by aboumadi          #+#    #+#             */
/*   Updated: 2022/04/10 22:18:44 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_f1(void* n)
{
	t_threads	**t_fork;
	t_time		*t_ph;
	int			nb;
	nb = *(int *)n;
	
	t_fork = (t_threads **)malloc(sizeof(t_threads));
	t_ph = (t_time *)malloc(sizeof(t_time));
	printf("Philo %d is thinking\n", nb);
	pthread_mutex_lock(&(*t_fork)[nb].mut_fork);
	printf("|%d|\n", nb);
	pthread_mutex_lock(&(*t_fork)[(nb+1) % t_ph->nb_philo].mut_fork);
	//printf("hello\n");
	printf("philo %d is eating\n", nb);
	sleep(t_ph->time_to_eat);
	pthread_mutex_unlock(&(*t_fork)[nb].mut_fork);
	pthread_mutex_unlock(&(*t_fork)[(nb+1) % t_ph->nb_philo].mut_fork);
	printf("philo %d is finish\n", nb);
}
int	main(int argc, char **argv)
{
	t_time		*time2;
	t_threads	*mt;
	int			i;
	
	i = 0;
	if (argc >= 5)
	{
		time2 = (t_time *)malloc(sizeof(t_time));
		mt = (t_threads *)malloc(sizeof(t_threads));
		get_time(argc, time2, argv);
		while (i < time2->nb_philo)
		{
			pthread_mutex_init(&(mt)[i].mut_fork, NULL);
			i++;
		}
		//printf("hello\n");
		i = 0;
		while (i < time2->nb_philo)
		{
			pthread_create(&(mt)[i].ph, NULL, (void *)ph_f1, &i);
			i++;
		}
		i = 0;
		while (i < time2->nb_philo)
		{
			pthread_join((mt)[i].ph, NULL);
			i++;
		}
	}
	else
		printf("error in number of parameters\n");
}