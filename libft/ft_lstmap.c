/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <alnoviko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:28:21 by alnoviko          #+#    #+#             */
/*   Updated: 2026/04/28 19:41:10 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*node;

	if (lst == NULL)
	{
		del(lst->content);
		return (NULL);
	}
	new = ft_lstnew(f(lst->content));
	lst = lst->next;
	while (lst != NULL)
	{
		node = ft_lstnew(f(lst->content));
		if (node == NULL)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, node);
		lst = lst->next;
	}
	return (new);
}

/* void *f(void *content)
{
	char *x = malloc(1);
	*x = *(char *)(content) + 1;
	return (x);
}
void del(void *content)
{
	*(char *)content = 0;
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
	t_list *l2 = ft_lstmap(l, f, del);
	ft_lstiter(l, print_element);
	printf("\n");
	ft_lstiter(l2, print_element);
	printf("\n");
} */