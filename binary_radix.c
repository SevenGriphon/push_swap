/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_radix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <alnoviko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 17:40:49 by alnoviko          #+#    #+#             */
/*   Updated: 2026/05/26 11:26:24 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back(t_list **a, t_list **b, int reverse, t_stats *stats)
{
	int	i;

	i = 0;
	while (*b != NULL)
	{
		do_pa(a, b, stats);
		// push(b, a);
		i++;
	}
	if (reverse)
	{
		while (i-- != 0)
			do_ra(a, stats);
			// rotate(a);
	}
}

void	sort_by_digit(t_list **a, t_list **b, int pos, t_stats *stats)
{
	int	i;
	int	size;
	int	digit;
	int	reverse;

	if (!needs_sorting(*a, pos))
		return ;
	reverse = needs_reverse_sort(*a, pos);
	size = ft_lstsize(*a);
	i = 0;
	while (i++ != size)
	{
		digit = get_binary_digit(*(int *)((*a)->content), pos);
		if ((!reverse && digit == 0) || (reverse && digit == 1))
			do_pb(a, b, stats);
			// push(a, b);
		else
			do_ra(a, stats);
			// rotate(a);
	}
	push_back(a, b, reverse, stats);
}

void	sort_by_sign(t_list **a, t_list **b, t_stats *stats)
{
	int	i;
	int	size;
	int	number;

	size = ft_lstsize(*a);
	i = 0;
	while (i != size)
	{
		number = *(int *)((*a)->content);
		if (number < 0)
			do_pb(a, b, stats);
			// push(a, b);
		else
			do_ra(a, stats);
			// rotate(a);
		i++;
	}
	i = 0;
	while (*b != NULL)
    {
		do_rrb(b, stats);
        // reverse_rotate(b);
		do_pa(a, b, stats);
        // push(b, a);
        i++;
    }
}

void	radix(t_list **a, t_list **b, t_stats *stats)
{
	int	max_size;
	int	i;

	max_size = find_longest(*a);
	i = 0;
	while (i != max_size)
	{
		sort_by_digit(a, b, i, stats);
		i++;
	}
	sort_by_sign(a, b, stats);
}
