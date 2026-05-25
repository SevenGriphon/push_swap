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

static void	sort_low_disorder(t_list **a)
{
	int	n;
	int	i;
	int	sorted;

	n = ft_len(*a) - 1;
	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		i = 0;
		while (i < n)
		{
			if (*(int *)(*a)->content > *(int *)(*a)->next->content)
			{
				swap(a);
				sorted = 0;
			}
			rotate(a);
			i++;
		}
		i = 0;
		while (i++ < n)
			reverse_rotate(a);
	}
}

void	sort_adaptive(t_list **a, t_list **b)
{
	double	disorder;

	disorder = compute_disorder(*a);
	if (disorder < 0.2)
		sort_low_disorder(a);
	else if (disorder < 0.5)
	{
		chunck(a, b);
		sort_meduim(a, b);
	}
	else
		radix(a, b);
}
