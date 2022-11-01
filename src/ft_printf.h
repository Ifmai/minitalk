/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 09:46:41 by hozdemir          #+#    #+#             */
/*   Updated: 2022/11/01 12:38:15 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

# include "../ft_print/libft/libft.h"

typedef struct t_listt
{
	char			flagstart;
	long			dec;
	int				cvalue;
	char			*string;
	unsigned int	unsval;
	unsigned int	xval;
	unsigned long	pval;
	int				rtn;

}					t_printf;

void	check_arg(const char *str, va_list pars, t_printf *prnt);
void	check_one(va_list pars, t_printf *prnt);
void	check_two(va_list pars, t_printf *prnt);
void	check_tree(va_list pars, t_printf *prnt);
void	decimal_to_hexa(t_printf *prnt, unsigned int nb);
void	decimal_to_hexap(t_printf *prnt, unsigned long nb);
void	unsigned_convert(t_printf *print, unsigned int nb);
void	reset_struck(t_printf *p);
int		ft_printf(const char *str, ...);

#endif