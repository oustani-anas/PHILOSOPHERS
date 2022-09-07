/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoustani <aoustani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 00:36:06 by aoustani          #+#    #+#             */
/*   Updated: 2022/09/02 23:53:14 by aoustani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_dead(t_philosopher *philo, t_philos_data *data, int i)
{
	if (data->eaten == data->number_of_philo)
	{
		data->stop = 1;
		return (0);
	}
	if ((get_current_time() - philo[i].last_meal) > data->time_to_die)
	{
		data->stop = 1;
		if (data->number_of_philo == 1)
			pthread_mutex_unlock(philo->right_fork);
		print_message(philo->data_p, 1, "died\n");
		return (0);
	}
	return (1);
}

void	*check_stop(void	*arg)
{
	t_philosopher	*philo;
	t_philos_data	*data;
	int				i;

	i = 0;
	philo = (t_philosopher *)arg;
	data = philo[0].data_p;
	while (1)
	{
		i = 0;
		while (i < data->number_of_philo)
		{
			if (!check_dead(philo, data, i))
				return (0);
			i++;
		}
	}
	return (NULL);
}
