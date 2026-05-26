/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <alnoviko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 17:39:31 by alnoviko          #+#    #+#             */
/*   Updated: 2026/05/26 17:02:32 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!*stack || !(*stack)->next)
	{
		return ;
	}
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	push(t_list **src, t_list **dest)
{
	t_list	*element;

	if (!*src)
	{
		return ;
	}
	element = *src;
	*src = (*src)->next;
	element->next = *dest;
	*dest = element;
}

void	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	first = *stack;
	last = *stack;
	while (last->next)
	{
		last = last->next;
	}
	if (first != last)
	{
		*stack = (*stack)->next;
	}
	last->next = first;
	first->next = NULL;
}

void	reverse_rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;
	t_list	*pre_last;

	first = *stack;
	last = *stack;
	pre_last = first;
	while (last->next)
	{
		pre_last = last;
		last = last->next;
	}
	*stack = last;
	last->next = first;
	pre_last->next = NULL;
}
