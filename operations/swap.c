/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <alnoviko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 16:29:03 by alnoviko          #+#    #+#             */
/*   Updated: 2026/05/26 17:02:55 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_sa(t_list **a, t_stats *s)
{
	swap(a);
	write(1, "sa\n", 3);
	if (s)
		s->sa++;
}

void	do_sb(t_list **b, t_stats *s)
{
	swap(b);
	write(1, "sb\n", 3);
	if (s)
		s->sb++;
}

void	do_ss(t_list **a, t_list **b, t_stats *s)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
	if (s)
		s->ss++;
}
