/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmp_and_join_str_zero_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanton2 <maanton2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 02:38:36 by maanton2          #+#    #+#             */
/*   Updated: 2024/11/14 02:54:51 by maanton2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

char	*ft_cmp_and_join_str_zero(char *raw_str, char *fmt_zero, int precision)
{
	char	*temp;
	char	*join;

	join = NULL;
	temp = NULL;
	if (ft_strncmp(raw_str, fmt_zero, precision) != 0)
	{
		temp = fmt_zero;
		join = ft_strjoin(fmt_zero, raw_str);
		if (!fmt_zero)
			return (NULL);
		free(temp);
	}
	return (join);
}
