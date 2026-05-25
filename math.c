/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <alnoviko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 17:52:39 by alnoviko          #+#    #+#             */
/*   Updated: 2026/05/25 17:52:49 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_log(unsigned int base, int n)
{
	int				result;
	unsigned int	nb;

	if (n < 0)
	{
		nb = n * -1;
	}
	else
	{
		nb = n;
	}
	result = 0;
	while (nb > base)
	{
		nb /= base;
		result++;
	}
	return (result + 1);
}

int	ft_pow(int base, int exponent)
{
	int	result;

	result = 1;
	while (exponent != 0)
	{
		result *= base;
		exponent--;
	}
	return (result);
}
