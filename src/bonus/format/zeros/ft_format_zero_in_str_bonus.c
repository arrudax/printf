/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_zero_in_str.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanton2 <maanton2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 22:24:02 by maanton2          #+#    #+#             */
/*   Updated: 2024/11/13 22:24:21 by maanton2         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_format_zero_in_str(const char *fmt, int precision, int field_width)
{
	int		i;
	char	*s;
	int		len_s;
	int		zeros;

	 len_s = (int)ft_strlen(fmt);
	if (len_s > precision && len_s > field_width)
		return ((char *)fmt);
	i = 0;
	zeros = precision - len_s;
	if (zeros == 0)
		return ((char *)fmt);
	if (zeros < 0)
		zeros = -zeros;
	s = (char *)malloc((zeros + 1) * sizeof(char));
	if (!s)
		return (NULL);
	while (zeros--)
		s[i++] = '0';
	s[i] = '\0';
	return (s);
}
