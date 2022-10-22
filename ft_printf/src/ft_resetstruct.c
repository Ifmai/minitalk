/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resetstruct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 09:41:35 by hozdemir          #+#    #+#             */
/*   Updated: 2022/10/18 09:41:49 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_struck(t_printf *p)
{
	p->flagstart = 0;
	p->dec = 0;
	p->cvalue = 0;
	p->string = 0;
	p->unsval = 0;
	p->xval = 0;
	p->pval = 0;
}
