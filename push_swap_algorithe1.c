/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithe1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <alnoviko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 16:23:26 by alnoviko          #+#    #+#             */
/*   Updated: 2026/05/26 17:34:20 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_pos(t_list *b)
{
	int	max_val;
	int	max_pos;
	int	pos;

	max_val = *(int *)b->content;
	max_pos = 0;
	pos = 0;
	while (b)
	{
		if (*(int *)b->content > max_val)
		{
			max_val = *(int *)b->content;
			max_pos = pos;
		}
		pos++;
		b = b->next;
	}
	return (max_pos);
}

void	bring_max_to_top(t_list **b, t_stats *stats)
{
	int	max;
	int	len;

	max = find_max_pos(*b);
	len = ft_len(*b);
	if (max <= len / 2)
	{
		while (max-- > 0)
			do_rb(b, stats);
	}
	else
	{
		len = len - max;
		while (len-- > 0)
			do_rrb(b, stats);
	}
}

void	sort_simple(t_list **a, t_list **b, t_stats *stats)
{
	stats->strategy = 2;
	while (*a)
		do_pb(a, b, stats);
	while (*b)
	{
		bring_max_to_top(b, stats);
		do_pa(a, b, stats);
	}
}
