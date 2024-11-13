/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanton2 <maanton2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 06:10:27 by maanton2          #+#    #+#             */
/*   Updated: 2024/11/13 07:31:10 by maanton2         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);
int		ft_vsprintf(char *fmt, va_list args);
char	*ft_parse_precision_and_width(char *fmt, int *precision, int *field_width);
char	*ft_handler_case(int c, va_list args);
int		ft_format_string(char *formated_str, int precision, int field_width);

#endif
