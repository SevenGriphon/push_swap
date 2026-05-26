/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <alnoviko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:25:23 by alnoviko          #+#    #+#             */
/*   Updated: 2026/04/29 17:37:19 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;
	t_list	*todel;

	next = *lst;
	while (next != NULL)
	{
		todel = next;
		next = next->next;
		del(todel->content);
		free(todel);
	}
	*lst = NULL;
}

/* void del(void *content)
{
	*(int *)content = 0;
}
void print_element(void *content)
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
	ft_lstclear(&l, del);
	ft_lstiter(l, print_element);
	printf("\n");
} */