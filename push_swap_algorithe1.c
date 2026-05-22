#include "push_swap.h"

int	find_max_pos(t_list *b)
{
	int	max_val;
	int	max_pos;
	int	pos;

	max_val = *(int *)b->content;
	max_pos = 0;
	pos = 0;
	while (b)
	{
		if (*(int *)b->content > max_val)
		{
			max_val = *(int *)b->content;
			max_pos = pos;
		}
		pos++;
		b = b->next;
	}
	return (max_pos);
}

void	bring_max_to_top(t_list **b)
{
	int	max;
	int	len;

	max = find_max_pos(*b);
	len = ft_len(*b);
	if (max <= len / 2)
	{
		while (max-- > 0)
			rotate(b);
	}
	else
	{
		len = len - max;
		while (len-- > 0)
			reverse_rotate(b);
	}
}

void	sort_simple(t_list **a, t_list **b)
{
	while (*a)
		push(a, b);
	while (*b)
	{
		bring_max_to_top(b);
		push(b, a);
	}
}
