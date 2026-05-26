/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <alnoviko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 17:46:27 by alnoviko          #+#    #+#             */
/*   Updated: 2026/04/28 20:22:52 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*p;

	c = (char) c;
	p = NULL;
	while (1 == 1)
	{
		if (*s == c)
		{
			p = (char *) s;
		}
		if (*s == 0)
		{
			break ;
		}
		s++;
	}
	return (p);
}

/* int main()
{
	char *haystack = "Hello World!";
	char needle = 'l';
	printf("%s\n", ft_strrchr(haystack, needle));
} */