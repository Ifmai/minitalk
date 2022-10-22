/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 08:12:36 by hozdemir          #+#    #+#             */
/*   Updated: 2022/10/18 11:03:00 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printf(const char *str, ...)
{
	va_list		arg;
	t_printfb	print;

	va_start(arg, str);
	print.rtn = 0;
	ft_reset(&print);
	ft_check_arg(str, arg, &print);
	va_end(arg);
	return (print.rtn);
}
