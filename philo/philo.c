/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 22:45:47 by aboumadi          #+#    #+#             */
/*   Updated: 2022/04/03 18:02:45 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_time	*time2;
	if (argc >= 5)
	{
		time2 = (t_time *)malloc(sizeof(t_time));
		get_time(argc, time2, argv);
	}
	else
		printf("error in number of parameters\n");
}