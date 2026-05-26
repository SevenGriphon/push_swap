/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <alnoviko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:09:18 by alnoviko          #+#    #+#             */
/*   Updated: 2026/04/28 19:41:55 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_isprint(int c)
{
	return (c >= ' ' && c <= '~');
}

/* int	main(void)
{
	printf("%c: %i\n", 'a', ft_isprint('a'));
	printf("%c: %i\n", '\t', ft_isprint('\t'));
} */