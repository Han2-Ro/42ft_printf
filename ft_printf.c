/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrother <hrother@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:38:56 by hrother           #+#    #+#             */
/*   Updated: 2023/09/15 22:24:54 by hrother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int	printchar(char c)
{
	return (write(1, &c, 1));
}

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
			write(1, str, 1);
			str++;
			c_count++;
			continue ;
		}
		str++;
		if (*str == 'c')
			c_count += printchar(va_arg(args, int));
		str++;
	}
	va_end(args);
	return (c_count);
}