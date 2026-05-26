/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_adaptive.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <alnoviko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 16:22:57 by alnoviko          #+#    #+#             */
/*   Updated: 2026/05/26 17:02:09 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_len(t_list *pile)
{
	int	taille;

	taille = 0;
	while (pile)
	{
		taille++;
		pile = pile->next;
	}
	return (taille);
}

double	compute_disorder(t_list *pile)
{
	t_list	*i;
	t_list	*j;
	double	mistakes;
	double	total;

	if (!pile || !pile->next)
		return (0.0);
	mistakes = 0;
	total = 0;
	i = pile;
	while (i)
	{
		j = i->next;
		while (j)
		{
			total++;
			if (*(int *)i->content > *(int *)j->content)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	return (mistakes / total);
}

void	sort_adaptive(t_list **a, t_list **b, t_stats *stats)
{
	int	n;
	int	simple;
	int	medium;
	int	complex;

	if (compute_disorder(*a) == 0)
	{
		return ;
	}
	n = ft_lstsize(*a);
	simple = (n / 2) * n + n;
	medium = 2 * n * my_sqrt(n);
	complex = (find_longest(*a) + 1) * 2 * n;
	if (simple <= medium && simple <= complex)
		sort_simple(a, b, stats);
	else if (medium <= complex)
		sort_meduim(a, b, stats);
	else
		radix(a, b, stats);
}
