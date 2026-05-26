/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <alnoviko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 17:44:33 by alnoviko          #+#    #+#             */
/*   Updated: 2026/04/28 19:40:48 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	while (i < n)
	{
		c1 = ((unsigned char *) s1)[i];
		c2 = ((unsigned char *) s2)[i];
		if (c1 != c2)
		{
			return (c1 - c2);
		}
		i++;
	}
	return (0);
}

/* int	main(void)
{
	char str[10] = {'a', 'b', 'c', 'd'};
	char str2[10] = {'a', 'b', 'c', 'd'};
	char str3[10] = {'a', 'b', 'c', 'e'};
	printf("%i\n", ft_memcmp(str, str2, 4));
	printf("%i\n", ft_memcmp(str, str3, 4));
	printf("%i\n", ft_memcmp(str, str3, 3));
} */