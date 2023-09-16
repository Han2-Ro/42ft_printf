/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrother <hrother@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:38:56 by hrother           #+#    #+#             */
/*   Updated: 2023/09/16 18:41:11 by hrother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_c(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_s(char *s)
{
	return (write(1, s, ft_strlen(s)));
}

/*
int	set_flags(char *s, t_flags *flags)
{
	int	i;

	flags->force_sign = 0;
	flags-> = 0;
	while (1)
	{

		if (*s == '.')
		(*s)++
	}
}
*/

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		c_count;

	va_start(args, str);
	c_count = 0;
	while (*str)
	{
		if (*str != '%')
		{
			c_count += write(1, str++, 1);
			continue ;
		}
		str++;
		if (*str == 'c')
			c_count += ft_print_c(va_arg(args, int));
		else if (*str == 's')
			c_count += ft_print_s(va_arg(args, char *));
		else if (*str == 'i' || *str == 'd')
			c_count += ft_print_i(va_arg(args, int));
		else if (*str == 'x')
			c_count += ft_print_x(va_arg(args, unsigned int), "0123456789abcdef");
		else if (*str == 'X')
			c_count += ft_print_x(va_arg(args, unsigned int), "0123456789ABCDEF");
		else if (*str == 'u')
			c_count += ft_print_u(va_arg(args, unsigned int));
		else if (*str == 'p')
			c_count += ft_print_p(va_arg(args, void *), "0123456789abcdef");
		else if (*str == '%')
			c_count += ft_print_c(*str);
		str++;
	}
	va_end(args);
	return (c_count);
}
