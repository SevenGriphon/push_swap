/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <alnoviko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 17:45:43 by alnoviko          #+#    #+#             */
/*   Updated: 2026/04/28 20:23:11 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	while (i < n)
	{
		c1 = (unsigned char) s1[i];
		c2 = (unsigned char) s2[i];
		if (c1 != c2)
		{
			return (c1 - c2);
		}
		if (c1 == 0)
		{
			break ;
		}
		i++;
	}
	return (0);
}

/* int	main(void)
{
	char *str = "abcd";
	char *str2 = "abcb";
	printf("%i\n", ft_strncmp(str, str2, 4));
} */