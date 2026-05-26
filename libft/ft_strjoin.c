/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <alnoviko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:52:39 by alnoviko          #+#    #+#             */
/*   Updated: 2026/04/28 19:58:27 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	int		j;
	char	*result;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	result = malloc(len);
	i = 0;
	while (s1[i] != 0)
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		result[i] = s2[j];
		j++;
		i++;
	}
	result[i] = '\0';
	return (result);
}

/* int	main(void)
{
	char *str = "Hello ";
	char *str2 = "world!";
	printf("%s\n", ft_strjoin(str, str2));
} */