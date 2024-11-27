/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanton2 <maanton2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 03:15:39 by maanton2          #+#    #+#             */
/*   Updated: 2024/11/21 18:41:33 by maanton2         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_vsprintf(char c, va_list args)
{
	char	*s;
	int		len;
	int		f_malloc;

	len = 0;
	s = NULL;
	f_malloc = 0;
	if (c == 'd' || c == 'i')
		s = ft_itoa(va_arg(args, int));
	else if (c == '%')
		s = "%";
	else if (c == 'u')
		s = ft_itoa(va_arg(args, unsigned int));
	else if (c == 'p')
	{
		s = ft_long_to_hex(va_arg(args, unsigned long), &f_malloc);
	}
	else if (c == 'X')
	{
		f_malloc = 1;
		s = ft_int_to_hex(va_arg(args, unsigned int), &f_malloc, 1);
	}
	/*else if (c == 'x')
	{
		f_malloc = 1;
		s = ft_int_to_hex(va_arg(args, unsigned int), &f_malloc, 0);
	}*/
	else if (c == 's')
		s = va_arg(args, char *);
	if (s != NULL)
		len = (int)ft_strlen(s);
	ft_putstr_fd(s, STDOUT);
	if (f_malloc)
		free(s);
	return (len);
}
