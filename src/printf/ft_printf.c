/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanton2 <maanton2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 06:09:14 by maanton2          #+#    #+#             */
/*   Updated: 2024/11/13 07:12:15 by maanton2         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */
 
#include "ft_printf.h"
 
int ft_printf(const char *format, ...)
{
	va_list	args;
	int		printed;
	char	*p_format;

	p_format = (char *)format;
	va_start(args, format);
	while (*p_format)
	{
		if (*p_format == '%')
		{
			p_format++;
			printed = ft_vsprintf(p_format, args);
		}
		p_format++;
	}
	va_end(args);
	return (printed);
}
