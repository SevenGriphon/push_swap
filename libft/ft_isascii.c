/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <alnoviko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:07:17 by alnoviko          #+#    #+#             */
/*   Updated: 2026/04/28 19:42:03 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

/* int	main(void)
{
	printf("%c: %i\n", 'a', ft_isalnum('a'));
	printf("%c: %i\n", 190, ft_isalnum(190));
} */