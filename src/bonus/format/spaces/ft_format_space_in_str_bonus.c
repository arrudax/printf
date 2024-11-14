/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_space_in_str_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanton2 <maanton2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 02:37:04 by maanton2          #+#    #+#             */
/*   Updated: 2024/11/14 04:24:58 by maanton2         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*ft_format_space_in_str(const char *fmt, int field_width)
{
	int		i;
	char	*s;
	int		spaces;
	int		len_fmt;

	len_fmt = (int)ft_strlen(fmt);
	spaces = field_width - len_fmt;
	if (len_fmt > field_width || spaces == 0)
		return ((char *)fmt);
	i = 0;
	if (spaces < 0)
		spaces = -spaces;
	s = (char *)malloc((spaces + 1) * sizeof(char));
	if (!s)
		return (NULL);
	while(spaces--)
		s[i++] = ' ';
	s[i] = '\0';
	return (s);
}
