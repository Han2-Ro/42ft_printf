/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrother <hrother@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:38:56 by hrother           #+#    #+#             */
/*   Updated: 2023/09/14 16:24:24 by hrother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		c_count;

	va_start(args, str);
	while (*str)
	{
		write(1, str, 1);
		str++;
		c_count++;
	}
	return (c_count);
}