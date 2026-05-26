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