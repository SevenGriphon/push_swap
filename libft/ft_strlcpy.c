/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <alnoviko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 17:51:38 by alnoviko          #+#    #+#             */
/*   Updated: 2026/04/28 19:39:10 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] != 0)
	{
		if (size > 0 && i < size - 1)
		{
			dst[i] = src[i];
		}
		i++;
	}
	if (size > 0)
	{
		if (size - 1 > i)
		{
			dst[i] = '\0';
		}
		else
		{
			dst[size - 1] = '\0';
		}
	}
	return (i);
}

/* int	main(void)
{
	char str[11];
	char *str2 = "Hello world! ._.";
	int i = ft_strlcpy(str, str2, 12);
	printf("%s (%i)\n", str, i);
} */