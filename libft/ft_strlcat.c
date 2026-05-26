/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <alnoviko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 17:45:23 by alnoviko          #+#    #+#             */
/*   Updated: 2026/04/28 19:39:23 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;

	dst_len = 0;
	while (dst[dst_len] != 0 && dst_len != size)
	{
		dst_len++;
	}
	src_len = 0;
	while (src[src_len] != 0)
	{
		if (size > 0 && (dst_len + src_len) < size - 1)
		{
			dst[dst_len + src_len] = src[src_len];
		}
		src_len++;
	}
	if ((dst_len) < size)
	{
		dst[size - 1] = '\0';
	}
	return (dst_len + src_len);
}

/* int	main(void)
{
	char str[10] = {"Hello "};
	char *str2 = "cat!!!";
	int i = ft_strlcat(str, str2, 10);
	printf("%s (%i)\n", str, i);
} */