/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:45:42 by hozdemir          #+#    #+#             */
/*   Updated: 2022/11/01 22:27:28 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void capture_signal(int incoming)
{
	static  int c = 0;
	static unsigned int i = 0;
	static unsigned int n = 128;
	if (incoming == SIGUSR1)
		i |= n;
	n /= 2;
	c++;
	if (c == 8)
	{
		write(1,&i,1);
		c = 0;
		i = 0;
		n = 128;
	}
}
int main(void)
{
	int	pid_t;
	
	pid_t = getpid();
	ft_printf("pid: %d\n",pid_t);
	signal(SIGUSR1, capture_signal);
	signal(SIGUSR2, capture_signal);
	while (1)
		pause();
	return (0);
}