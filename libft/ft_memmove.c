/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <alnoviko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:39:51 by alnoviko          #+#    #+#             */
/*   Updated: 2026/04/28 19:40:38 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dp;
	const char	*sp;
	int			i;

	dp = dest;
	sp = src;
	if (src > dest)
	{
		i = 0;
		while (i < (int)n)
		{
			dp[i] = sp[i];
			i++;
		}
	}
	else
	{
		i = n - 1;
		while (i >= 0)
		{
			dp[i] = sp[i];
			i--;
		}
	}
	return (dest);
}

/* int	main(void)
{
	char str[10] = {'a', 'b', 'c', 'd'};
	ft_memcpy(str, str+1, 2);
	printf("%s\n", str);
} */