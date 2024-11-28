/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanton2 <maanton2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 02:32:34 by maanton2          #+#    #+#             */
/*   Updated: 2024/11/27 20:46:49 by maanton2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		args;
	size_t		printed;
	char		*p_format;

	if (!format)
		return (-1);
	printed = 0;
	va_start(args, format);
	p_format = (char *)format;
	while (*p_format)
	{
		if (*p_format == '%')
		{
			p_format++;
			printed += ft_vsprintf(*p_format, args);
		}
		else
		{
			printed += ft_putchar_fd(*p_format, STDOUT);
		}
		p_format++;
	}
	va_end(args);
	return (printed);
}
