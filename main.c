/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <alnoviko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 17:56:08 by alnoviko          #+#    #+#             */
/*   Updated: 2026/05/26 11:51:11 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parse_flags(int argc, char **argv, int *strategy)
{
	int	i;

	i = 1;
	*strategy = 0;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (ft_strncmp(argv[i], "--simple", 9) == 0)
			*strategy = 1;
		else if (ft_strncmp(argv[i], "--medium", 9) == 0)
			*strategy = 2;
		else if (ft_strncmp(argv[i], "--complex", 10) == 0)
			*strategy = 3;
		i++;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	int		i;
	int		strategy;
	t_list	*a;
	t_list	*b;
	t_stats	stats;

	new_stats(&stats);
	if (argc < 2)
		return (0);
	i = parse_flags(argc, argv, &strategy);
	a = NULL;
	b = NULL;
	while (i < argc)
		ft_lstadd_back(&a, create_node(argv[i++]));
	if (strategy == 1)
		sort_simple(&a, &b, &stats);
	else if (strategy == 2)
		sort_meduim(&a, &b, &stats);
	else if (strategy == 3)
		radix(&a, &b, &stats);
	else
		sort_adaptive(&a, &b, &stats);
	print_stack(a);
	printf("%i\n", stats.sa + stats.sb + stats.ss + stats.pa + stats.pb + stats.ra + stats.rb + stats.rr + stats.rra + stats.rrb + stats.rrr);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	return (0);
}
