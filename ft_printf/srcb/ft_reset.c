/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 04:17:02 by hozdemir          #+#    #+#             */
/*   Updated: 2022/10/18 08:00:11 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_reset(t_printfb *print)
{
	print->int_tmp = 0;
	print->dvalue = 0;
	print->string = 0;
	print->unsvalue = 0;
	print->fconvert = 0;
	print->fnegative = 0;
	print->fplus = 0;
	print->fzero = 0;
	print->fdot = 0;
	print->fspace = 0;
	print->format = 0;
	print->fnum = 0;
	print->fdotdot = 0;
	print->neg = 0;
	print->hexlen = 0;
	print->dlen = 0;
	print->ulen = 0;
	print->slen = 0;
	print->fconlen = 0;
}
