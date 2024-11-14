/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmp_and_join_str_space_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanton2 <maanton2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 02:40:58 by maanton2          #+#    #+#             */
/*   Updated: 2024/11/14 02:54:41 by maanton2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

char	*ft_cmp_and_join_str_space(char *fmt_zero, char *fmt_space, int field_width)
{
	char	*temp;
	char	*join;

	join = NULL;
	temp = NULL;
	if (ft_strncmp(fmt_space, fmt_zero, field_width) != 0)
	{
		temp = fmt_space;
		join = ft_strjoin(fmt_space, fmt_zero);
		if (!fmt_space)
			return (NULL);
		free(temp);
	}
	return (join);
}
