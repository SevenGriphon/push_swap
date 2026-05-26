/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <alnoviko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 17:50:03 by alnoviko          #+#    #+#             */
/*   Updated: 2026/04/28 14:33:15 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_calloc(size_t n, size_t size)
{
	void	*result;

	if ((n != 0 && size > 2147483647 / n))
	{
		return (NULL);
	}
	result = malloc(n * size);
	if (result == NULL)
	{
		return (NULL);
	}
	ft_bzero(result, n * size);
	return (result);
}

/* int	main(void)
{
	char *str = ft_calloc(10, sizeof(char));
	free(str);
} */