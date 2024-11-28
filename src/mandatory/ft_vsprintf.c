/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanton2 <maanton2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 03:15:39 by maanton2          #+#    #+#             */
/*   Updated: 2024/11/27 21:10:18 by maanton2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static char	*ft_valid_str(char *s)
{
	if (!s)
		return ("(null)");
	else
		return (s);
}

static char	*ft_handle_case(char c, va_list args)
{
	char	*s;
	int		len;
	int		f_malloc;

	len = 0;
	s = NULL;
	f_malloc = 0;
	if (c == 's')
		s = ft_valid_str(va_arg(args, char *));
	else if (c == 'p')
		s = ft_long_to_hex(va_arg(args, unsigned long), &f_malloc);
	if (c == 'd' || c == 'i')
		s = ft_itoa(va_arg(args, int));
	else if (c == 'u')
		s = ft_itoa_a(va_arg(args, unsigned int));
	else if (c == 'X')
		s = ft_int_to_hex(va_arg(args, unsigned int), &f_malloc, 1);
	else if (c == 'x')
		s = ft_int_to_hex(va_arg(args, unsigned int), &f_malloc, 0);
	else if (c == '%')
		s = "%";
	if (f_malloc)
		free(s);
	return (s);
}

int	ft_vsprintf(char c, va_list args)
{
	char	*s;
	int		len;

	len = 0;
	s = NULL;
	if (c == 'c')
		len = ft_putchar_fd(va_arg(args, int), STDOUT);
	else
		s = ft_handle_case(c, args);
	if (s != NULL)
		len = ft_putstr_fd(s, STDOUT);
	return (len);
}
