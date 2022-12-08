/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:45:47 by hozdemir          #+#    #+#             */
/*   Updated: 2022/12/08 12:51:44 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(unsigned int a, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (a >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i--;
	}
}

void	send_pid(unsigned int a, int pid)
{
	int	i;

	i = 31;
	while (i >= 0)
	{
		if (a >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i--;
	}
}

void	send_newline(unsigned int a, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (a >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i--;
	}
}

void	bravo(int incoming)
{
	ft_printf("Message sending successful.");
	exit(0);
}

int	main(int ac, char **av)
{
	int		i;
	int		pid;
	int		client_pid;

	client_pid = getpid();
	i = 0;
	pid = ft_atoi(av[1]);
	send_pid(client_pid, pid);
	signal(SIGUSR1, bravo);
	if (ac != 3)
	{
		ft_printf("./client <SERVER PID> [MESSAGE]");
		exit(0);
	}
	while (av[2][i])
	{
		send_signal(av[2][i], pid);
		i++;
	}
	send_newline('\n', pid);
	while (1)
		pause();
}
