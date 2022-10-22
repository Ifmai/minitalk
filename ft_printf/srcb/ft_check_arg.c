/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 04:14:37 by hozdemir          #+#    #+#             */
/*   Updated: 2022/10/18 06:17:07 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_check(char c, const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

void	ft_putchar_fd1(char c, int fd, t_printfb *print)
{
	write(fd, &c, 1);
	print->rtn++;
}

void	ft_check_arg(const char *str, va_list arg, t_printfb *print)
{
	size_t	i;
	size_t	j;
	char	*flag;

	i = 0;
	while (*(str + i))
	{
		if (*(str + i) == '%')
		{
			i++;
			j = i;
			while (ft_check(*(str + j), "cspdiuxX%") == 1)
				j++;
			flag = ft_substr((str + i), 0, j - i + 1);
			flag_check(print, flag);
			ft_print(arg, print);
			free(flag);
			ft_reset(print);
			i = j;
		}
		else
			ft_putchar_fd1(*(str + i), 1, print);
		i++;
	}
}
