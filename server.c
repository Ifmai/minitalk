/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:45:42 by hozdemir          #+#    #+#             */
/*   Updated: 2022/12/08 12:48:34 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static unsigned int	g_client_pid = 0;

void	pid_signal(int incoming)
{
	static unsigned int	_32 = 2147483648;
	static unsigned int	pid_sig = 0;

	if (incoming == SIGUSR1)
			g_client_pid |= _32;
	_32 /= 2;
	pid_sig++;
	if (pid_sig == 32)
	{
		pid_sig = 0;
		_32 = 2147483648;
	}
}

int	char_signal(int incoming)
{
	static unsigned int	char_sig = 0;
	static unsigned int	i = 0;
	static unsigned int	n = 128;
	char				x;

	if (incoming == SIGUSR1)
			i |= n;
	n /= 2;
	char_sig++;
	if (char_sig == 8)
	{
		x = i;
		write(1, &i, 1);
		char_sig = 0;
		i = 0;
		n = 128;
		return (x);
	}
	return (0);
}

void	capture_signal(int incoming)
{
	static unsigned int	c = 0;
	char				x;

	x = 0;
	if (c >= 32 && c < 40)
	{
		x = char_signal(incoming);
		c++;
		if (c == 40 && x != '\n')
			c = 32;
		else if (x == '\n')
		{
			c = 0;
			kill(g_client_pid, SIGUSR1);
			g_client_pid = 0;
		}
	}
	else if (c < 32)
	{
		pid_signal(incoming);
		c++;
	}
}

int	main(void)
{
	int	pid_t;

	pid_t = getpid();
	ft_printf("pid: %d\n", pid_t);
	signal(SIGUSR1, capture_signal);
	signal(SIGUSR2, capture_signal);
	while (1)
		pause();
	return (0);
}
