/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fct_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gel-kasr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 04:49:28 by gel-kasr          #+#    #+#             */
/*   Updated: 2019/12/09 19:54:26 by gel-kasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	sub_print_long(long i, t_fmt fmt, int nb_space, int nb_zero)
{
	int len;

	len = ft_intlen(i) + ((fmt.plus || fmt.space) && i >= 0);
	if (!fmt.minus && ((fmt.min_width > len && !fmt.zero) || nb_space))
		ft_putnchar(' ', nb_space);
	if ((fmt.plus || fmt.space) && i >= 0)
		ft_putchar((fmt.plus) ? '+' : ' ');
	if ((fmt.zero && fmt.min_width > len) || fmt.precision)
	{
		ft_putnchar('-', (i < 0) ? 1 : 0);
		ft_putnchar('0', nb_zero);
		ft_putnbr((i < 0) ? -i : i);
	}
	else if (i || !fmt.point)
		ft_putnbr(i);
	if (fmt.minus && fmt.min_width > len)
		ft_putnchar(' ', nb_space);
}

int			print_long(va_list *ap, t_fmt fmt)
{
	long	i;
	int		len;
	int		nb_space;
	int		nb_zero;

	i = va_arg(*ap, long);
	len = ft_intlen(i) + ((fmt.plus || fmt.space) && i >= 0);
	nb_zero = (fmt.precision + ((i < 0) || ((fmt.plus || fmt.space) &&
		i >= 0)) > len) ? fmt.precision - len + ((i < 0) || ((fmt.plus
		|| fmt.space) && i >= 0)) : 0;
	if (!fmt.point && fmt.zero)
		nb_zero = (fmt.min_width > len) ? fmt.min_width - len : 0;
	len += nb_zero;
	nb_space = (fmt.min_width > len) ? fmt.min_width - len +
		(!i && !fmt.precision && fmt.point) : 0;
	sub_print_long(i, fmt, nb_space, nb_zero);
	return (len + nb_space - (!i && !fmt.precision && fmt.point));
}
