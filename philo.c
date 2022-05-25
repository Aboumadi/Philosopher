/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 22:45:47 by aboumadi          #+#    #+#             */
/*   Updated: 2022/05/23 22:39:53 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	*philo;
	int		i;

	i = 0;
	if (argc == 5 || argc == 6)
	{
		philo = get_args(argc, argv);
		if (!philo || (initialisation(philo) == 1))
		{
			free(philo);
			printf("error\n");
			exit(0);
		}
		if (creat_thread(philo, philo->data_of_philo) == 1)
		{
			printf("error in creat of threads\n");
			exit (0);
		}
	}
	else
		printf("error in number of parameters\n");
}
