/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <alnoviko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 17:52:38 by alnoviko          #+#    #+#             */
/*   Updated: 2026/04/28 20:23:09 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t			i;
	size_t			j;
	unsigned char	bigc;
	unsigned char	littlec;

	if (big[0] == 0 && little[0] == 0)
		return ((char *) big);
	i = 0;
	while (i < len && big[i] != 0)
	{
		j = 0;
		bigc = big[i + j];
		littlec = little[j];
		while (bigc != 0 && littlec != 0 && bigc == littlec && i + j <= len)
		{
			bigc = big[i + j];
			littlec = little[j];
			j++;
		}
		if (littlec == 0)
			return ((char *) &big[i]);
		i++;
	}
	return (NULL);
}

/* int main()
{
	char *haystack = "Hello World!";
	char *needle = "lo";
	printf("%s\n", ft_strnstr(haystack, needle, 5));
} */