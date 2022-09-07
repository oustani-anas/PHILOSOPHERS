/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoustani <aoustani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:13:37 by aoustani          #+#    #+#             */
/*   Updated: 2022/09/02 12:11:59 by aoustani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philosopher		*philosophers;
	t_philos_data		info;

	if (!check_args(ac, av))
	{
		printf("\e[31m\e[1mINVALID ARGUMENTS");
		return (0);
	}
	if (!args_info(&info, ac, av))
	{
		printf("\e[31m\e[1mERROR IN ARGUMENTS");
		return (0);
	}
	philosophers = malloc(sizeof(t_philosopher) * info.number_of_philo);
	if (!philosophers)
		return (0);
	init_forks(&info);
	init_philo(&info, philosophers);
	finish_all(&info, philosophers);
}
