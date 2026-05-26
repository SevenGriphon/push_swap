/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <alnoviko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:00:00 by alnoviko          #+#    #+#             */
/*   Updated: 2026/05/26 12:00:00 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_bench_strategy(double disorder, int strategy)
{
	if (strategy == 1)
		ft_printf_fd(2, "[bench] strategy: Simple / O(n^2)\n");
	else if (strategy == 2)
		ft_printf_fd(2, "[bench] strategy: Medium / O(n*sqrt(n))\n");
	else if (strategy == 3)
		ft_printf_fd(2, "[bench] strategy: Complex / O(n log n)\n");
	else if (disorder < 0.2)
		ft_printf_fd(2, "[bench] strategy: Adaptive / O(n)\n");
	else if (disorder < 0.5)
		ft_printf_fd(2, "[bench] strategy: Adaptive / O(n*sqrt(n))\n");
	else
		ft_printf_fd(2, "[bench] strategy: Adaptive / O(n log n)\n");
}

void	print_bench(t_stats *s, double disorder, int strategy)
{
	int	total;
	int	hundredths;
	int	pct_int;
	int	pct_frac;

	total = s->sa + s->sb + s->ss + s->pa + s->pb
		+ s->ra + s->rb + s->rr + s->rra + s->rrb + s->rrr;
	hundredths = (int)(disorder * 10000 + 0.5);
	pct_int = hundredths / 100;
	pct_frac = hundredths % 100;
	ft_printf_fd(2, "[bench] disorder: %d.%d%d%%\n",
		pct_int, pct_frac / 10, pct_frac % 10);
	print_bench_strategy(disorder, strategy);
	ft_printf_fd(2, "[bench] total_ops: %d\n", total);
	ft_printf_fd(2, "[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n",
		s->sa, s->sb, s->ss, s->pa, s->pb);
	ft_printf_fd(2, "[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		s->ra, s->rb, s->rr, s->rra, s->rrb, s->rrr);
}
