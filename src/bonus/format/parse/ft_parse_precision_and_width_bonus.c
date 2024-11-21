/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_precision_and_width_bonus.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanton2 <maanton2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 06:40:43 by maanton2          #+#    #+#             */
/*   Updated: 2024/11/21 18:52:50 by maanton2         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*ft_parse_precision_and_width(char *fmt,
		int *precision,
		int *field_width)
{
	char	*is_negative;
	char	*p_fmt;
	int		sign;

	sign = 1;
	p_fmt = ft_strchr(fmt, '.');
	is_negative = ft_strchr(fmt, '-');
	if (is_negative != NULL)
		sign = -1;
	if (p_fmt != NULL)
	{
		p_fmt++;
		(*precision) = ft_atoi(p_fmt);
		while (*p_fmt && ft_isdigit(*p_fmt))
			p_fmt++;
	}
	while (*fmt && ft_isdigit(*fmt) && fmt != p_fmt)
	{
		if (*field_width == 0)
		{
			if (p_fmt != NULL)
			{
				//separar no ponto para a atoi n retornar 0 por existir - e . 
			}
			(*field_width) = ft_atoi(fmt);
		}
		fmt++;
	}
	if(!p_fmt)
		p_fmt = fmt;
	if (is_negative != NULL)
		(*field_width) *= sign;
	return (p_fmt);
}
