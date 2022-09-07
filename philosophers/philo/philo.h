/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoustani <aoustani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 00:34:42 by aoustani          #+#    #+#             */
/*   Updated: 2022/09/02 12:02:01 by aoustani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo_data
{
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	int				stop;
	long			start_time;
	long			print_time;
	int				eaten;
	pthread_mutex_t	print_message;
	pthread_mutex_t	*forks;
	pthread_t		check_dead;
}	t_philos_data;

typedef struct s_philosopher
{
	int				id;
	long			last_meal;
	int				num_eat;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	t_philos_data	*data_p;
	pthread_t		my_thread;
}	t_philosopher;

int		ft_atoi(char *str);
int		ft_strlen(char *str);
int		ft_is_number(char *str);
int		check_args(int ac, char **av);
int		args_info(t_philos_data *p, int ac, char **av);
void	*routine(void	*arg);
void	lock_fork(t_philosopher *philo);
void	unlock_fork(t_philosopher *philo);
int		philo_eat(t_philosopher *philo);
void	*check_stop(void	*arg);
int		check_dead(t_philosopher *philo, t_philos_data *data, int i);
void	print_message(t_philos_data *data, int id, char *message);
void	finish_all(t_philos_data *data, t_philosopher *philos);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_usleep(long time);
long	get_current_time(void);
void	init_forks(t_philos_data *data_p);
void	init_philo(t_philos_data *data_p, t_philosopher *philos);

#endif