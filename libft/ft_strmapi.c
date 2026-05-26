/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <alnoviko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:53:59 by alnoviko          #+#    #+#             */
/*   Updated: 2026/04/29 17:27:23 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	int		i;

	result = malloc(ft_strlen(s) + 1);
	i = 0;
	while (s[i] != 0)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = 0;
	return (result);
}

/* char f(unsigned int i, char c)
{
	if (i % 2 == 1)
	{
		return ('-');
	}
	else
	{
		return (c);
	}
}
int	main(void)
{
	char *str = "kebab";
	printf("%s\n", ft_strmapi(str, f));
} */