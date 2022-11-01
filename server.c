/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:45:42 by hozdemir          #+#    #+#             */
/*   Updated: 2022/11/01 12:58:09 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void capture_signal(int incoming)
{
	if (incoming == SIGUSR1)
		ft_printf("\nSignal One");
	else if (incoming == SIGUSR2)
		ft_printf("\nSignal Two");
}
int main(void)
{
	int pid_t = getpid();
	ft_printf("pid: %d",pid_t);
	signal(SIGUSR1, capture_signal);
	signal(SIGUSR2, capture_signal);
	while(1);
	return (0);
}