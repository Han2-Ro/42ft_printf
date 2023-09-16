/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrother <hrother@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:26:07 by hrother           #+#    #+#             */
/*   Updated: 2023/09/16 19:11:48 by hrother          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_H
# define FTPRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

/*typedef struct s_flags
{
	int	leftjust;
	int	pad_0;
	int	percision;
	int	preceed_0x;
	int	nosign_space;
	int	force_sign;
}	t_flags;*/

int	ft_printf(const char *str, ...);

int	ft_print_i(int n);
int	ft_print_x(unsigned int n, char *base);
int	ft_print_u(unsigned int n);
int	ft_print_p(unsigned long n, char *base);
#endif
