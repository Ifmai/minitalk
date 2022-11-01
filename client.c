/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:45:47 by hozdemir          #+#    #+#             */
/*   Updated: 2022/11/01 19:57:58 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
	
void send_signal(unsigned int a ,int pid)
{
	int i = 7;

	while(i >= 0)
	{
		if(a >> i & 1)
			kill(pid,SIGUSR1);
		else
			kill(pid,SIGUSR2);
		usleep(100);
		i--;
	}
}

int main(int ac, char **av)
{
	int		i;
	int		pid;
	i = 0;
	pid = ft_atoi(av[1]);
	while (av[2][i])
	{
		send_signal(av[2][i],pid);
		i++;
	}
}