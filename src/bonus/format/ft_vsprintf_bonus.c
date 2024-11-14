/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanton2 <maanton2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 03:15:39 by maanton2          #+#    #+#             */
/*   Updated: 2024/11/14 07:27:26 by maanton2         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
/*
typedef struct s_format_spec {
	int		len;
	char	*flag;
	char	*raw_str;
	int		precision;
	int		field_width;
	int		is_negative;
    int		zero_pad;
} t_format_spec;
*/
int	ft_vsprintf(char **fmt, va_list args)
{
	int		len;
	char	*flag;
	char	*raw_str;
	int		precision;
	int		field_width;

	len = 0;
	raw_str = NULL;
	precision = 0;
	field_width = 0;
	flag = "n";
	if (**fmt == '.' || ft_isdigit(**fmt))
	{
		if (**fmt == '0')
		{
			flag = "zero";
			(*fmt) = ft_parse_precision_and_width(*fmt, &precision, &field_width);
			raw_str = ft_handler_case(**fmt, args);
		}
		else
		{
			(*fmt) = ft_parse_precision_and_width(*fmt, &precision, &field_width);
			raw_str = ft_handler_case(**fmt, args);
		}
		raw_str = ft_format_string(raw_str, precision, field_width, flag);
	}
	if (!raw_str)
		raw_str = ft_handler_case(**fmt, args);
	ft_putstr_fd(raw_str, STDOUT);
	len = (int)ft_strlen(raw_str);
	free(raw_str);
	return (len);
}
