/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <alnoviko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 16:29:29 by alnoviko          #+#    #+#             */
/*   Updated: 2026/05/26 17:02:45 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_pa(t_list **a, t_list **b, t_stats *s)
{
	push(b, a);
	write(1, "pa\n", 3);
	if (s)
		s->pa++;
}

void	do_pb(t_list **a, t_list **b, t_stats *s)
{
	push(a, b);
	write(1, "pb\n", 3);
	if (s)
		s->pb++;
}
