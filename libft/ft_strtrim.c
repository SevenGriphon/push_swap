/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <alnoviko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:54:41 by alnoviko          #+#    #+#             */
/*   Updated: 2026/04/29 17:51:02 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	isin(char const c, char const *set)
{
	while (*set != 0)
	{
		if (*set == c)
		{
			return (1);
		}
		set++;
	}
	return (0);
}

static int	get_len(char const *s1, char const *set)
{
	int	len;
	int	i;
	int	start;

	len = ft_strlen(s1);
	i = 0;
	while (isin(s1[i], set) == 1)
		i++;
	len -= i;
	start = i;
	i = ft_strlen(s1) - 1;
	while (isin(s1[i], set) == 1 && i != (start - 1))
	{
		i--;
		len--;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		i;
	int		len;
	int		start;

	i = 0;
	while (isin(s1[i], set) == 1)
		i++;
	start = i;
	len = get_len(s1, set);
	result = malloc(len + 1);
	i = 0;
	while (result != NULL && i < len)
	{
		result[i] = s1[start + i];
		i++;
	}
	result[i] = 0;
	return (result);
}
