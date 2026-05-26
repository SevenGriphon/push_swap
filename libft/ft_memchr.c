/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <alnoviko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:37:39 by alnoviko          #+#    #+#             */
/*   Updated: 2026/04/28 19:40:51 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	c = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s + i) == c)
		{
			return ((void *)(s + i));
		}
		i++;
	}
	return (NULL);
}

/* int	main(void)
{
	char str[10] = {'a', 'b', 'c', 'd'};
	printf("%s\n", (char *)ft_memchr(str, 'c', 4));
} */