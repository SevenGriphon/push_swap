/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <alnoviko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:09:39 by alnoviko          #+#    #+#             */
/*   Updated: 2026/04/29 17:22:48 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	get_size(long int n)
{
	int	size;

	size = 0;
	if (n < 0)
	{
		size++;
	}
	while (n != 0)
	{
		size++;
		n /= 10;
	}
	if (size == 0)
	{
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*result;
	int		size;
	int		sign;

	nb = n;
	size = get_size(nb);
	sign = 0;
	if (nb < 0)
	{
		sign = 1;
		nb *= -1;
	}
	result = malloc(size + 1);
	result[size] = '\0';
	if (sign == 1)
		result[0] = '-';
	while (size - sign > 0)
	{
		result[size - 1] = nb % 10 + '0';
		nb /= 10;
		size--;
	}
	return (result);
}

/* int	main(void)
{
	printf("%s\n", ft_itoa(-42));
} */