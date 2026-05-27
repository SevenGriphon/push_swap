/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outil_printf.c                                  :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+    */
/*   By: ldoucet <ldoucet@learner.42.tech>          +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+          */
/*   Created: 2026/05/09 10:39:58 by ldoucet           #+#    #+#            */
/*   Updated: 2026/05/09 10:40:02 by ldoucet          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pft_putchar(int fd, char c)
{
	write(fd, &c, 1);
	return (1);
}

int	pft_strstring(int fd, char *s)
{
	int	i;

	if (!s)
		return (pft_strstring(fd, "(null)"));
	i = 0;
	while (s[i] != '\0')
	{
		pft_putchar(fd, s[i]);
		i++;
	}
	return (i);
}

int	pft_putnbr(int fd, int n)
{
	int		count;
	char	c;

	count = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		count++;
		n = -n;
	}
	if (n >= 10)
		count += pft_putnbr(fd, n / 10);
	c = (n % 10) + '0';
	write(fd, &c, 1);
	count++;
	return (count);
}

int	pft_putunsigned(int fd, unsigned int n)
{
	int		count;
	char	c;

	count = 0;
	if (n >= 10)
		count += pft_putunsigned(fd, n / 10);
	c = (n % 10) + '0';
	write(fd, &c, 1);
	count++;
	return (count);
}

int	pft_puthex(int fd, unsigned long nb, char *base)
{
	int	i;

	i = 0;
	if (nb < 16)
		i += pft_putchar(fd, base[nb]);
	else
	{
		i += pft_puthex(fd, nb / 16, base);
		i += pft_puthex(fd, nb % 16, base);
	}
	return (i);
}
