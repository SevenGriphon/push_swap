/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <alnoviko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:58:36 by alnoviko          #+#    #+#             */
/*   Updated: 2026/04/28 20:23:01 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		c += 'A' - 'a';
	}
	return (c);
}

/* int main()
{
	printf("%c\n", ft_toupper('A'));
	printf("%c\n", ft_toupper('a'));
	printf("%c\n", ft_toupper('4'));
} */