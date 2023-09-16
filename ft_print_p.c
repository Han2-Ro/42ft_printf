/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrother <hrother@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:05:17 by hrother           #+#    #+#             */
/*   Updated: 2023/09/16 19:10:59 by hrother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_p(unsigned long n, char *base)
{
	int				c_count;
	char			c;

	c_count = 0;
	if (n >= 16)
		c_count += ft_print_p(n / 16, base);
	c = base[n % 16];
	c_count += write(1, &c, 1);
	return (c_count);
}
