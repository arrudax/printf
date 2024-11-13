/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_case.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanton2 <maanton2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 05:27:02 by maanton2          #+#    #+#             */
/*   Updated: 2024/11/13 07:24:31 by maanton2         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*ft_handler_case(int c, va_list args)
{
	char	*s;

	s = NULL;
	if (c == 'd')
		s = ft_itoa(va_arg(args, int));
	return (s);
}
