/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <alnoviko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 17:56:08 by alnoviko          #+#    #+#             */
/*   Updated: 2026/05/26 17:36:07 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parse_flags(int argc, char **argv, int *strategy, int *bench)
{
	int	i;

	i = 1;
	*strategy = 0;
	*bench = 0;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (ft_strncmp(argv[i], "--simple", 9) == 0)
			*strategy = 1;
		else if (ft_strncmp(argv[i], "--medium", 9) == 0)
			*strategy = 2;
		else if (ft_strncmp(argv[i], "--complex", 10) == 0)
			*strategy = 3;
		else if (ft_strncmp(argv[i], "--adaptive", 11) == 0)
			*strategy = 0;
		if (ft_strncmp(argv[i], "--bench", 8) == 0)
			*bench = 1;
		i++;
	}
	return (i);
}

static void	run_sort(t_list **a, t_list **b, t_stats *s, int strategy)
{
	if (strategy == 1)
		sort_simple(a, b, s);
	else if (strategy == 2)
		sort_meduim(a, b, s);
	else if (strategy == 3)
		radix(a, b, s);
	else
		sort_adaptive(a, b, s);
}

static void	sort_and_bench(t_list **a, int strategy, int bench)
{
	t_list	*b;
	t_stats	stats;
	double	disorder;

	new_stats(&stats);
	b = NULL;
	disorder = compute_disorder(*a);
	run_sort(a, &b, &stats, strategy);
	if (bench)
		print_bench(&stats, disorder);
	ft_lstclear(a, free);
	ft_lstclear(&b, free);
}

int	main(int argc, char **argv)
{
	int		i;
	int		strategy;
	int		bench;
	t_list	*a;

	if (argc < 2)
		return (0);
	i = parse_flags(argc, argv, &strategy, &bench);
	if (i >= argc)
		return (0);
	if (!validate_args(argc, argv, i))
		return (ft_error(NULL));
	a = NULL;
	while (i < argc)
		ft_lstadd_back(&a, create_node(argv[i++]));
	if (has_duplicates(a))
		return (ft_error(&a));
	sort_and_bench(&a, strategy, bench);
	return (0);
}
