/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <alnoviko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 17:56:08 by alnoviko          #+#    #+#             */
/*   Updated: 2026/05/26 11:09:02 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_list *stack)
{
	while (stack)
	{
		ft_printf("%i", *(int *)(stack->content));
		if (stack->next)
			ft_printf(" > ");
		stack = stack->next;
	}
	ft_printf("\n");
}

t_list	*create_node(char *arg)
{
	int		*value;
	t_list	*node;

	value = malloc(sizeof(int));
	*value = ft_atoi(arg);
	node = ft_lstnew(value);
	return (node);
}

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

void	new_stats(t_stats *stats)
{
	stats->sa = 0;
	stats->sb = 0;
	stats->ss = 0;
	stats->pa = 0;
	stats->pb = 0;
	stats->ra = 0;
	stats->rb = 0;
	stats->rr = 0;
	stats->rra = 0;
	stats->rrb = 0;
	stats->rrr = 0;
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
		sort_simple(&a, &b);
	else if (strategy == 2)
		sort_meduim(&a, &b);
	else if (strategy == 3)
		radix(&a, &b);
	else
		sort_adaptive(&a, &b);
	return (0);
}
