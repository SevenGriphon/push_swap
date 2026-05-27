/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithe2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <alnoviko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 16:23:48 by alnoviko          #+#    #+#             */
/*   Updated: 2026/05/27 15:27:43 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_minmax(t_list *a, int *min, int *max)
{
	int	val;

	*min = *(int *)a->content;
	*max = *min;
	while (a)
	{
		val = *(int *)a->content;
		if (val < *min)
			*min = val;
		if (val > *max)
			*max = val;
		a = a->next;
	}
}

// data = {int cmin, int cmax, int is_last}
static void	push_chunk(t_list **a, t_list **b, int data[3], t_stats *stats)
{
	int	size_a;
	int	rotations;
	int	val;

	size_a = ft_lstsize(*a);
	rotations = 0;
	while (*a && rotations < size_a)
	{
		val = *(int *)(*a)->content;
		if (val >= data[0] && (data[2] || val < data[1]))
		{
			do_pb(a, b, stats);
			rotations = 0;
			size_a--;
		}
		else
		{
			do_ra(a, stats);
			rotations++;
		}
	}
}

static int	get_num_chunks(t_list *a)
{
	int	total;
	int	chunk_size;

	total = ft_lstsize(a);
	chunk_size = my_sqrt(total);
	return ((total + chunk_size - 1) / chunk_size);
}

void	chunck(t_list **a, t_list **b, t_stats *stats)
{
	int	num_chunks;
	int	min_val;
	int	max_val;
	int	chunk;
	int	data[3];

	get_minmax(*a, &min_val, &max_val);
	num_chunks = get_num_chunks(*a);
	chunk = 0;
	while (chunk < num_chunks)
	{
		data[0] = min_val + chunk * (max_val - min_val) / num_chunks;
		data[1] = min_val + (chunk + 1) * (max_val - min_val) / num_chunks;
		data[2] = chunk == num_chunks - 1;
		push_chunk(a, b, data, stats);
		chunk++;
	}
}

void	sort_meduim(t_list **a, t_list **b, t_stats *stats)
{
	stats->strategy = 2;
	chunck(a, b, stats);
	while (*b)
	{
		bring_max_to_top(b, stats);
		do_pa(a, b, stats);
	}
}
