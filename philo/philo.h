/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 22:46:17 by aboumadi          #+#    #+#             */
/*   Updated: 2022/05/23 22:46:14 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct th
{
	int				id;
	int				fork_left;
	int				fork_right;
	int				nb_of_eat;
	long long		check_die;
	pthread_t		ph;
	struct data		*philo;
}	t_th;

typedef struct data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_time_to_eat;
	int				counter;
	int				die;
	int				n_of_eat;
	long long		start_time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	eat;
	pthread_mutex_t	print;
	pthread_mutex_t	death;
	t_th			*data_of_philo;
}	t_data;

int			ft_atoi(char *str2);
t_data		*get_args(int argc, char **av);
int			check_num(char *str);
int			ft_isdigit(int n);
int			initialisation(t_data *philo);
int			initialisation_mutex(t_data *philo);
int			initialisation_philo(t_data *philo);
int			creat_thread(t_data *philo, t_th *ph);
long long	current_time(void);
void		ft_print(t_data *philo, int id, char *str);
void		ft_check_death(t_data *data, t_th *philo);
void		how_mutch_eat(t_data *data, t_th *ph);
void		ending(t_data *philo);
void		*routine(void *philo);

#endif
