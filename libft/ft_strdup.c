/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <alnoviko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:51:48 by alnoviko          #+#    #+#             */
/*   Updated: 2026/04/29 14:35:19 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strdup(const char *s)
{
	char	*result;
	int		i;

	result = malloc(ft_strlen(s)+1);
	i = 0;
	while (s[i] != 0)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = s[i];
	return (result);
}

/* int	main(void)
{
	char *str = "abcd";
	char *str2 = ft_strdup(str);
	printf("%s\n", str2);
} */