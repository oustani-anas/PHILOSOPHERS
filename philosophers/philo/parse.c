/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoustani <aoustani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 18:14:07 by aoustani          #+#    #+#             */
/*   Updated: 2022/09/02 11:54:37 by aoustani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	args_info(t_philos_data *p, int ac, char **av)
{
	p->number_of_philo = ft_atoi(av[1]);
	p->time_to_die = ft_atoi(av[2]);
	p->time_to_eat = ft_atoi(av[3]);
	p->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
	{
		p->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
		if (p->number_of_times_each_philosopher_must_eat <= 0)
			return (0);
	}
	else
		p->number_of_times_each_philosopher_must_eat = -1;
	if (p->number_of_philo <= 0 || p->time_to_die <= 0 || p->time_to_eat <= 0
		|| p->time_to_sleep <= 0)
		return (0);
	return (1);
}

int	check_args(int n, char **arg)
{
	int	i;

	i = 1;
	if (n < 5 || n > 6)
		return (0);
	else
	{
		while (arg[i])
		{
			if (!ft_strlen(arg[i]) || !ft_is_number(arg[i]))
			{
				return (0);
			}
			i++;
		}
	}
	return (1);
}
