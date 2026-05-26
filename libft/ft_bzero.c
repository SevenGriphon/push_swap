/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <alnoviko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 17:54:02 by alnoviko          #+#    #+#             */
/*   Updated: 2026/04/28 14:30:29 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/* int	main(void)
{
	int i = 0;
	int size = 10;
	char p[10];
	ft_memset(p, 'a', size);
	printf("before: ");
	while (i < size)
	{
		printf("%i ", p[i]);
		i++;
	}
	printf("\nafter: ");
	ft_bzero(p, size);
	i = 0;
	while (i < size)
	{
		printf("%i ", p[i]);
		i++;
	}
	printf("\n");
} */