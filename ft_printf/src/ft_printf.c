/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 09:49:07 by hozdemir          #+#    #+#             */
/*   Updated: 2022/10/18 09:49:52 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list		pars;
	t_printf	specter;

	va_start(pars, str);
	specter.rtn = 0;
	check_arg(str, pars, &specter);
	va_end(pars);
	return (specter.rtn);
}
