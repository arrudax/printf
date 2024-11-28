/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_to_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanton2 <maanton2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:52:52 by maanton2          #+#    #+#             */
/*   Updated: 2024/11/27 20:46:06 by maanton2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	ft_rev_tab(char *tab, size_t size)
{
	char	temp;
	size_t	iterator;
	size_t	iterator_reverse;

	iterator = 0;
	iterator_reverse = size - 1;
	if (size <= 0)
		return ;
	while (iterator < iterator_reverse)
	{
		temp = tab[iterator];
		tab[iterator] = tab[iterator_reverse];
		tab[iterator_reverse] = temp;
		iterator++;
		iterator_reverse--;
	}
	tab[size] = '\0';
}

char	*ft_long_to_hex(unsigned long ptr, int *f_malloc)
{
	size_t	i;
	char	*hex;
	int		remainder;

	i = 0;
	*f_malloc = 1;
	if (ptr == 0)
		return (ft_strdup("(nil)"));
	hex = (char *)malloc(20 * sizeof(char));
	if (!hex)
		return (ft_strdup("(nil)"));
	while (ptr > 0)
	{
		remainder = ptr % 16;
		if (remainder < 10)
			hex[i] = '0' + remainder;
		else
			hex[i] = 'a' + (remainder - 10);
		ptr /= 16;
		i++;
	}
	hex[i++] = 'x';
	hex[i++] = '0';
	ft_rev_tab(hex, i);
	return (hex);
}
