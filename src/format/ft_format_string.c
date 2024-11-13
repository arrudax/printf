/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanton2 <maanton2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 07:32:06 by maanton2          #+#    #+#             */
/*   Updated: 2024/11/13 07:57:59 by maanton2         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		ft_format_string(char *formated_str, int precision, int field_width)
{
	if (precision > 0 && field_width > 0)
	{
		printf("%s\n", formated_str);
		printf("%d\n", precision);
		printf("%d\n", field_width);
	}
	return (1);
}
