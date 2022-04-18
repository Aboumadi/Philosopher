/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 22:45:47 by aboumadi          #+#    #+#             */
/*   Updated: 2022/04/17 01:00:45 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_f1(int *n)
{
	t_th	**t_fork;
	t_time		*t_ph;
	int			nb;
	//nb = *(int *)n;
	
	t_fork = (t_th **)malloc(sizeof(t_th));
	t_ph = (t_time *)malloc(sizeof(t_time));
	nb = t_ph->nb_philo;
	printf("Philo %d is thinking\n", *n);
	puts("start");
	pthread_mutex_lock((*t_fork)[*n].mut_fork);
	puts("end1");
	printf("|%d|\n", *n);
	puts("end");
	pthread_mutex_lock((*t_fork)[(*n+1) % nb].mut_fork);
	//printf("hello\n");
	printf("philo %d is eating\n", *n);
	sleep(t_ph->time_to_eat);
	pthread_mutex_unlock((*t_fork)[*n].mut_fork);
	pthread_mutex_unlock((*t_fork)[(*n+1) % nb].mut_fork);
	printf("philo %d is finish\n", *n);
}
int	main(int argc, char **argv)
{
	t_data	*time2;
	t_th	*ph;
	int		i;
	
	i = 0;
	if (argc == 5 || argc == 6)
	{
		//time2 = (t_time *)malloc(sizeof(t_time));
		//mt = (t_th *)malloc(sizeof(t_th) * time2->nb_philo);
		time2 = get_time(argc, argv);
		if (!time2);
		{
			printf("error 1\n");
			exit(0);
		}
		if (!get_th(time2, &ph));
		{
			printf("error 2\n");
			free(time2);
			exit (0);
		}
		/*while (i < time2->nb_philo)
		{
			pthread_mutex_init((mt)[i].mut_fork, NULL);
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
		}*/
	}
	else
		printf("error in number of parameters\n");
}