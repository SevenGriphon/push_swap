/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <alnoviko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:38:40 by alnoviko          #+#    #+#             */
/*   Updated: 2026/04/28 19:40:42 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dp;
	const char	*sp;

	dp = dest;
	sp = src;
	i = 0;
	while (i < n)
	{
		dp[i] = sp[i];
		i++;
	}
	return (dp);
}

/* int	main(void)
{
	char str[10] = {'a', 'b', 'c', 'd'};
	char str2[10];
	ft_memcpy(str2, str, 3);
	printf("%s\n", str2);
} */