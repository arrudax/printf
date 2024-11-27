/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanton2 <maanton2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 06:10:27 by maanton2          #+#    #+#             */
/*   Updated: 2024/11/14 06:18:58 by maanton2         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifndef STDOUT
# define STDOUT 1
# endif

# include <stdarg.h>
# include <stdio.h>

// printf
int		ft_printf(const char *format, ...);
int		ft_vsprintf(char c, va_list args);
char	*ft_long_to_hex(unsigned long ptr, int *f_malloc);
char	*ft_int_to_hex(unsigned int ptr, int *f_malloc, int flag_parse);
	// handler
char	*ft_handler_case(int c, va_list args);

// format
char	*ft_parse_precision_and_width(char *fmt, int *precision, int *field_width);
char	*ft_format_string(char *raw_str, int precision, int field_width, char *flag);
char	*ft_format_zero_in_str(const char *fmt, int precision, int field_width);
char	*ft_format_space_in_str(const char *fmt, int field_width);
char	*ft_format_zero_pad(char *fmt, int *field_width);

// CMP
char	*ft_cmp_and_join_str_space(char *fmt_zero, char *fmt_space, int field_width);
char	*ft_cmp_and_join_str_zero(char *raw_str, char *fmt_zero, int precision);

#endif
