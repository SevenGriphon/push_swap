/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <alnoviko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:52:07 by alnoviko          #+#    #+#             */
/*   Updated: 2026/04/28 19:39:38 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		f(i, &s[i]);
		i++;
	}
}

/* void f(unsigned int i, char* c)
{
	if (i % 2 == 1)
	{
		*c = '-';
	}
}
int	main(void)
{
	char str[10] = {'a', 'b', 'c', 'd'};
	ft_striteri(str, f);
	printf("%s\n", str);
} */