/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <alnoviko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:58:03 by alnoviko          #+#    #+#             */
/*   Updated: 2026/04/29 17:51:18 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start,
size_t len)
{
	size_t	i;
	size_t	reslen;
	size_t	slen;
	char	*result;

	reslen = 0;
	slen = ft_strlen(s);
	while (slen > start + reslen && reslen < len)
	{
		reslen++;
	}
	result = malloc(reslen + 1);
	if (result == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < reslen)
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = 0;
	return (result);
}

/* int main()
{
	char *str = "Don't take it out of context";
	printf("%s\n", ft_substr(str, 14, 14));
} */