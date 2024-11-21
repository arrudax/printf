/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_case_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanton2 <maanton2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 05:27:02 by maanton2          #+#    #+#             */
/*   Updated: 2024/11/21 16:57:30 by maanton2         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*ft_handler_case(int c, va_list args)
{
	char	*s;

	s = NULL;
	if (c == 'd')
	{
		s = ft_itoa(va_arg(args, int));
		if (!s)
		{
			return (NULL);
		}
	}
	return (s);
}
