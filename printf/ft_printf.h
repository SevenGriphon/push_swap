/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <alnoviko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 16:49:56 by alnoviko          #+#    #+#             */
/*   Updated: 2026/05/05 19:50:15 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

void	ft_putchar(int c);
int		putstr(const char *str);
int		handle_percent(char c, va_list args);
int		ft_printf(const char *format, ...);
int		fstring(char *arg);
int		finteger(int arg);
int		fhex(unsigned long arg, char c);
int		funsigned(unsigned int n);
int		fpointer(void *arg);
char	*ft_bitoa(unsigned long n, char *base);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);
size_t	ft_strlen(const char *s);
#endif