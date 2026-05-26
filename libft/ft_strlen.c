/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <alnoviko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:53:12 by alnoviko          #+#    #+#             */
/*   Updated: 2026/04/28 20:29:04 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (*s != 0)
	{
		len++;
		s++;
	}
	return (len);
}

/* int	main(void)
{
	char *str = "This sentence contains 36 characters";
	printf("%li\n", ft_strlen(str));
} */