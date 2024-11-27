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

	len = 0;
	s = NULL;
	if (c == 'd' || c == 'i')
		s = ft_itoa(va_arg(args, int));
	else if (c == '%')
		s = "%";
	else if (c == 'u')
		s = ft_itoa(va_arg(args, unsigned int));
	else if (c == 'p')
		s = ft_long_to_hex(va_arg(args, void *));
	else if (c == 's')
		s = va_arg(args, char *);
	if (s != NULL)
		len = (int)ft_strlen(s);
	ft_putstr_fd(s, STDOUT);
	return (len);
}
