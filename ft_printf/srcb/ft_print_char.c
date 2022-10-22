/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 04:28:05 by hozdemir          #+#    #+#             */
/*   Updated: 2022/10/18 04:35:32 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_print_char(t_printfb *print)
{
	int	i;

	i = 0;
	ft_putchar_fd(print->dvalue, 1);
	print->rtn++;
	if (print -> fzero > print->fnum)
		print->int_tmp = print->fzero;
	else
		print->int_tmp = print->fnum;
	while (i++ < print->int_tmp - 1)
	{
		ft_putchar_fd(' ', 1);
		print->rtn++;
	}
}

void	ft_print_char2(t_printfb *print)
{
	int	i;

	i = 0;
	if (print -> fzero > print->fnum)
		print->int_tmp = print->fzero;
	else
		print->int_tmp = print->fnum;
	while (i++ < print->int_tmp - 1)
	{
		if (print->fzero > print->fnum)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		print->rtn++;
	}
	ft_putchar_fd(print->dvalue, 1);
	print->rtn++;
}
