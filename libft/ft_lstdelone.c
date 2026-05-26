/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <alnoviko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:25:52 by alnoviko          #+#    #+#             */
/*   Updated: 2026/04/28 19:41:26 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
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
	ft_lstdelone(l->next->next->next, del);
	l->next->next->next = NULL;
	ft_lstiter(l, print_element);
	printf("\n");
} */