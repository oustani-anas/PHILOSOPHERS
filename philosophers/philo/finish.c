/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoustani <aoustani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 06:47:33 by aoustani          #+#    #+#             */
/*   Updated: 2022/09/02 11:54:08 by aoustani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(t_philos_data *data, int id, char *state)
{
	if (data->stop == 1 && ft_strncmp(state, "died", 4))
		return ;
	pthread_mutex_lock(&data->print_message);
	data->print_time = get_current_time() - data->start_time;
	printf("%lu       %d   %s \n", data->print_time, id, state);
	pthread_mutex_unlock(&data->print_message);
}

long	get_current_time(void)
{
	struct timeval	time;
	long			timenow;

	gettimeofday(&time, NULL);
	timenow = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (timenow);
}

void	ft_usleep(long time)
{
	long int	start;

	start = 0;
	start = get_current_time();
	while ((get_current_time() - start) < time)
		usleep(50);
	return ;
}

void	finish_all(t_philos_data *data, t_philosopher *philos)
{
	int	i;

	i = 0;
	while (i < data->number_of_philo)
	{
		pthread_join(philos[i].my_thread, NULL);
		i++;
	}
	i = 0;
	while (i < data->number_of_philo)
	{
		pthread_mutex_destroy(philos[i].right_fork);
		i++;
	}
	pthread_join(data->check_dead, NULL);
	free(philos);
	free(data->forks);
}
