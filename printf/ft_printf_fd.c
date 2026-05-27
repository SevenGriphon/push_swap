/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+    */
/*   By: ldoucet <ldoucet@learner.42.tech>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+          */
/*   Created: 2026/05/09 10:38:00 by ldoucet           #+#    #+#            */
/*   Updated: 2026/05/09 10:38:00 by ldoucet          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putptr_fd(int fd, void *ptr)
{
	if (!ptr)
		return (write(fd, "(nil)", 5));
	pft_putchar(fd, '0');
	pft_putchar(fd, 'x');
	return (pft_puthex(fd, (unsigned long)ptr, "0123456789abcdef") + 2);
}

static int	ft_handle_num_fd(int fd, char spec, va_list *args)
{
	if (spec == 'd' || spec == 'i')
		return (pft_putnbr(fd, va_arg(*args, int)));
	if (spec == 'u')
		return (pft_putunsigned(fd, va_arg(*args, unsigned int)));
	if (spec == 'x')
		return (pft_puthex(fd, va_arg(*args, unsigned int),
				"0123456789abcdef"));
	if (spec == 'X')
		return (pft_puthex(fd, va_arg(*args, unsigned int),
				"0123456789ABCDEF"));
	return (-1);
}

static int	ft_handle_format_fd(int fd, char spec, va_list *args)
{
	char	c;
	int		n;

	if (spec == 'c')
	{
		c = (char)va_arg(*args, int);
		write(fd, &c, 1);
		return (1);
	}
	else if (spec == 's')
		return (pft_strstring(fd, va_arg(*args, char *)));
	else if (spec == 'p')
		return (ft_putptr_fd(fd, va_arg(*args, void *)));
	else if (spec == '%')
		return (write(fd, "%", 1));
	n = ft_handle_num_fd(fd, spec, args);
	if (n != -1)
		return (n);
	pft_putchar(fd, '%');
	return (pft_putchar(fd, spec) + 1);
}

int	ft_printf_fd(int fd, const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			count += ft_handle_format_fd(fd, format[i + 1], &args);
			i++;
		}
		else
			count += pft_putchar(fd, format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
