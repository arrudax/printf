/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_zero_pad_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanton2 <maanton2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 05:33:38 by maanton2          #+#    #+#             */
/*   Updated: 2024/11/14 06:20:50 by maanton2         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*ft_format_zero_pad(char *fmt, int *field_width)
{
	char	*formated;

	formated = "";
	(void)fmt;

	printf("*** %d", *field_width);
	return (formated);
}

