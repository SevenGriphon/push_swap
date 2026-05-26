/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <alnoviko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:27:01 by alnoviko          #+#    #+#             */
/*   Updated: 2026/04/28 19:41:14 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
	{
		return (NULL);
	}
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

/* int	main(void)
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
	printf("%c\n", *(char *)(ft_lstlast(l)->content));
} */