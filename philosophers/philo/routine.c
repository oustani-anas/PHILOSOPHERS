/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoustani <aoustani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 02:33:56 by aoustani          #+#    #+#             */
/*   Updated: 2022/09/02 12:16:24 by aoustani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void	*arg)
{
	t_philosopher	*philo;
	int				i;

	philo = (t_philosopher *)arg;
	i = 0;
	while (philo->data_p->stop == 0)
	{
		philo_eat(philo);
		if (philo->data_p->stop == 1)
			return (0);
		print_message(philo->data_p, philo->id, "is sleeping");
		ft_usleep(philo->data_p->time_to_sleep);
		if (philo->data_p->stop == 1)
			return (0);
		print_message(philo->data_p, philo->id, "is thinking");
		i++;
	}
	return (NULL);
}

void	lock_fork(t_philosopher *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		print_message(philo->data_p, philo->id, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_message(philo->data_p, philo->id, "has taken a fork");
		if (philo->data_p->stop == 1)
			return ;
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_message(philo->data_p, philo->id, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_message(philo->data_p, philo->id, "has taken a fork");
		if (philo->data_p->stop == 1)
			return ;
	}
}

void	unlock_fork(t_philosopher *philo)
{
	if (philo->id % 2 != 0)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
}

int	philo_eat(t_philosopher *philo)
{
	lock_fork(philo);
	print_message(philo->data_p, philo->id, "is eating");
	philo->last_meal = get_current_time();
	ft_usleep(philo->data_p->time_to_eat);
	philo->num_eat++;
	if ((philo->num_eat) == (
			philo->data_p->number_of_times_each_philosopher_must_eat))
		philo->data_p->eaten++;
	unlock_fork(philo);
	if (philo->data_p->stop == 1)
		return (1);
	return (0);
}
