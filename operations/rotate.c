/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <alnoviko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 16:29:57 by alnoviko          #+#    #+#             */
/*   Updated: 2026/05/26 17:02:52 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_ra(t_list **a, t_stats *s)
{
	rotate(a);
	write(1, "ra\n", 3);
	if (s)
		s->ra++;
}

void	do_rb(t_list **b, t_stats *s)
{
	rotate(b);
	write(1, "rb\n", 3);
	if (s)
		s->rb++;
}

void	do_rr(t_list **a, t_list **b, t_stats *s)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
	if (s)
		s->rr++;
}
