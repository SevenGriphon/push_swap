/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <alnoviko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:26:23 by alnoviko          #+#    #+#             */
/*   Updated: 2026/04/28 19:41:18 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/* void print_element(void *content)
{
	printf("%c", *(char *)content);
}
int	main(void)
{
	t_list *l = NULL;
	int c1 = '3';
	int c2 = '.';
	int c3 = '1';
	int c4 = '5';
	ft_lstadd_back(&l, ft_lstnew(&c1));
	ft_lstadd_back(&l, ft_lstnew(&c2));
	ft_lstadd_back(&l, ft_lstnew(&c3));
	ft_lstadd_back(&l, ft_lstnew(&c4));
	ft_lstiter(l, print_element);
	printf("\n");
} */