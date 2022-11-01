/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:45:47 by hozdemir          #+#    #+#             */
/*   Updated: 2022/11/01 14:24:28 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int pid = 41077;

int signal_send(int pid , char *send_array)
{
	
}
int main()
{
	kill(pid , SIGUSR1);
	usleep(40);
	kill(pid , SIGUSR2);
}