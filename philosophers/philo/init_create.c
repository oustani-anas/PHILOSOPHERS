/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoustani <aoustani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 21:48:39 by aoustani          #+#    #+#             */
/*   Updated: 2022/09/02 11:53:37 by aoustani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_forks(t_philos_data *data_p)
{
	int	i;

	i = 0;
	data_p->forks = malloc(sizeof(pthread_mutex_t) * data_p->number_of_philo);
	while (i < data_p->number_of_philo)
	{
		pthread_mutex_init(&data_p->forks[i], NULL);
		i++;
	}
}

void	init_philo(t_philos_data *data_p, t_philosopher *philos)
{
	int	i;

	i = 0;
	data_p->start_time = get_current_time();
	while (i < data_p->number_of_philo)
	{
		philos[i].id = i + 1;
		philos[i].right_fork = &data_p->forks[i];
		if (i == 0)
			philos[i].left_fork = &data_p->forks[data_p->number_of_philo - 1];
		else
			philos[i].left_fork = &data_p->forks[i - 1];
		philos[i].data_p = data_p;
		philos[i].num_eat = 0;
		philos[i].last_meal = data_p->start_time;
		philos[i].data_p->stop = 0;
		pthread_create(&philos[i].my_thread, NULL, &routine, &philos[i]);
		i++;
	}
	pthread_create(&data_p->check_dead, NULL, &check_stop, philos);
}
