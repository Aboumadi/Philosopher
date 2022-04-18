/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 22:46:17 by aboumadi          #+#    #+#             */
/*   Updated: 2022/04/17 01:04:13 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct data
{
	int	nb_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nb_time_to_eat;
	int	counter;
}	t_data;

typedef struct th
{
	int	id;
	pthread_mutex_t	mut_fork_left;
	pthread_mutex_t	mut_fork_right;
	pthread_t		ph;
}	t_th;

int		ft_atoi(char *str2);
t_data	*get_time(int argc, char **av);
int		check_num(char *str);
int		ft_isdigit(int n);
int		ft_work1(t_data *time, t_th **ph);
int		get_th(t_data *time, t_th **ph);

#endif