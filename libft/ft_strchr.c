/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <alnoviko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 17:51:03 by alnoviko          #+#    #+#             */
/*   Updated: 2026/04/28 19:39:53 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	c = (char) c;
	p = NULL;
	while (1 == 1)
	{
		if (*s == c)
		{
			p = (char *) s;
			break ;
		}
		if (*s == 0)
		{
			break ;
		}
		s++;
	}
	return (p);
}

/* int	main(void)
{
	char *str = "these aren't the droids you're looking for";
	char c = 'a';
	printf("%s\n", ft_strchr(str, c));
	
} */