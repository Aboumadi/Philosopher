/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 22:46:17 by aboumadi          #+#    #+#             */
/*   Updated: 2022/04/03 17:16:08 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
//# include <stdarg.h>
//# include <fcntl.h>
# include <stdio.h>

typedef struct time
{
	int	nb_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nb_time_to_eat;
}	t_time;

typedef struct threads
{
	pthread_mutex_t mut;

}	t_threads;

int		ft_atoi(char *str2);
void	get_time(int argc, t_time *time, char **av);
int		check_num(char *str);
int		ft_isdigit(int n);

#endif