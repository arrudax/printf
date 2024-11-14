/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_precision_and_width_bonus.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanton2 <maanton2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 06:40:43 by maanton2          #+#    #+#             */
/*   Updated: 2024/11/14 06:44:39 by maanton2         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*ft_parse_precision_and_width(char *fmt,
		int *precision,
		int *field_width)
{
	char	*p_fmt;

	p_fmt = ft_strchr(fmt, '.');
	if (p_fmt != NULL && *precision == 0)
	{
		p_fmt++;
		(*precision) += ft_atoi(p_fmt);
		while (*p_fmt && ft_isdigit(*p_fmt))
			p_fmt++;
	}
	while (*fmt && ft_isdigit(*fmt) && fmt != p_fmt)
	{
		if (*field_width == 0)
			(*field_width) += ft_atoi(fmt);
		fmt++;
	}
	if(!p_fmt)
		p_fmt = fmt;
	return (p_fmt);
}
