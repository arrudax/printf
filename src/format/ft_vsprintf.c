/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanton2 <maanton2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 03:15:39 by maanton2          #+#    #+#             */
/*   Updated: 2024/11/13 07:42:34 by maanton2         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_vsprintf(char *fmt, va_list args)
{
	int		len;
	char	*formated_str;
	int		precision;
	int		field_width;

	len = 0;
	precision = 0;
	field_width = 0;
	formated_str = NULL;
	if (*fmt == '.' || ft_isdigit(*fmt))
	{
		if (*fmt == '0')
			printf("%s", fmt);
		else
		{
			fmt = ft_parse_precision_and_width(fmt, &precision, &field_width);
			formated_str = ft_handler_case(*fmt, args);
		}
		len = ft_format_string(formated_str, precision, field_width);
	}
	return (len);
}
