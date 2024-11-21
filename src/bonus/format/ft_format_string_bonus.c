/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_string_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanton2 <maanton2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 07:32:06 by maanton2          #+#    #+#             */
/*   Updated: 2024/11/21 16:58:09 by maanton2         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*ft_format_string(char *raw_str, int precision, int field_width, char *flag)
{
	char	*fmt_zero;
	char	*fmt_space;
	char	*formated;
	char	*is_negative;

	formated = "";
	fmt_zero = "";
	fmt_space = "";
	is_negative = ft_strchr(raw_str, '-');
	if (field_width < 0)
	{
		fmt_zero = ft_format_zero_in_str((const char *)raw_str, precision, field_width);
		if (!fmt_zero)
			return (NULL);
		formated = ft_cmp_and_join_str_zero(raw_str, fmt_zero, precision);
	}
	if (precision > 0 && field_width > 0)
	{
		fmt_zero = ft_format_zero_in_str((const char *)raw_str, precision, field_width);
		if (!fmt_zero)
			return (NULL);
		fmt_zero = ft_cmp_and_join_str_zero(raw_str, fmt_zero, precision);
		fmt_space = ft_format_space_in_str((const char *)fmt_zero, field_width);
		if (!fmt_space)
			return (NULL);
		formated = ft_cmp_and_join_str_space(fmt_zero, fmt_space, field_width);
	}
	if (precision == 0 && field_width > 0)
	{
		fmt_space = ft_format_space_in_str((const char *)raw_str, field_width);
		if (!fmt_space)
			return (NULL);
		formated = ft_cmp_and_join_str_space(raw_str, fmt_space, field_width);
	}
	if (precision > 0 && field_width == 0)
	{
		fmt_zero = ft_format_zero_in_str((const char *)raw_str, precision, field_width);
		if (!fmt_zero)
			return (NULL);
		formated = ft_cmp_and_join_str_zero(raw_str, fmt_zero, precision);
	}
	if (ft_strnstr(flag, "zero", 4) != NULL)
	{
		fmt_zero = ft_format_zero_in_str((const char *)raw_str, field_width, field_width);
		if (!fmt_zero)
			return (NULL);
		formated = ft_cmp_and_join_str_zero(raw_str, fmt_zero, field_width);
	}
	if (is_negative != NULL)
	{
		fmt_zero = ft_format_zero_in_str((const char *)raw_str, field_width, field_width);
		if (!fmt_zero)
			return (NULL);
		if (ft_strlen(fmt_zero) > 2)
			fmt_zero[0] = '-';
		formated = ft_cmp_and_join_str_zero(is_negative + 1, fmt_zero, field_width);
		fmt_space = ft_format_space_in_str((const char *)formated, field_width);
		if (!fmt_space)
			return (NULL);
		formated = ft_cmp_and_join_str_space(formated, fmt_space, field_width);
	}

	return (formated);
}
