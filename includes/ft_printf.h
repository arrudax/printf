/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanton2 <maanton2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 06:10:27 by maanton2          #+#    #+#             */
/*   Updated: 2024/11/27 21:00:56 by maanton2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifndef STDOUT
#  define STDOUT 1
# endif

# include <stdarg.h>
# include <stdio.h>

// printf
int		ft_printf(const char *format, ...);
int		ft_vsprintf(char c, va_list args);
char	*ft_long_to_hex(unsigned long ptr, int *f_malloc);
char	*ft_int_to_hex(unsigned int ptr, int *f_malloc, int flag_parse);
char	*ft_itoa_a(unsigned int n);

#endif
