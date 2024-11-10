/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanton2 <maanton2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 06:09:14 by maanton2          #+#    #+#             */
/*   Updated: 2024/11/10 08:30:30 by maanton2         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int ft_printf(const char *s, ...)
{
	va_list	args;
	va_start(args, s);

	printf("HELLLLO");
	va_end(args);
	return (1);
}
