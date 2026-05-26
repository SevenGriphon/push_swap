/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <alnoviko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:24:34 by alnoviko          #+#    #+#             */
/*   Updated: 2026/04/28 19:41:37 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
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
	ft_lstadd_front(&l, ft_lstnew(&c1));
	ft_lstiter(l, print_element);
	printf("\n");
	ft_lstadd_front(&l, ft_lstnew(&c2));
	ft_lstadd_front(&l, ft_lstnew(&c3));
	ft_lstadd_front(&l, ft_lstnew(&c4));
	ft_lstiter(l, print_element);
	printf("\n");
} */