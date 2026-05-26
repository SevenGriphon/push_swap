/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <alnoviko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:40:26 by alnoviko          #+#    #+#             */
/*   Updated: 2026/04/28 14:33:09 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*p;

	i = 0;
	p = s;
	while (i < n)
	{
		p[i] = c;
		i++;
	}
	return (s);
}

/* int	main(void)
{
	int i = 0;
	int size = 10;
	char p[10];
	ft_memset(p, 'a', size);
	while (i < size)
	{
		printf("%i ", p[i]);
		i++;
	}
	printf("\n");
} */