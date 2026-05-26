/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <alnoviko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 16:30:25 by alnoviko          #+#    #+#             */
/*   Updated: 2026/05/26 17:02:49 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_rra(t_list **a, t_stats *s)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
	if (s)
		s->rra++;
}

void	do_rrb(t_list **b, t_stats *s)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
	if (s)
		s->rrb++;
}

void	do_rrr(t_list **a, t_list **b, t_stats *s)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
	if (s)
		s->rrr++;
}
