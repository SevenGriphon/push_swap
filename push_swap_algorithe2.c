#include "push_swap.h"

int	my_sqrt(int n)
{
	int	x;
	int	y;

	if (n < 2)
		return (n);
	x = n;
	y = (x + 1) / 2;
	while (y < x)
	{
		x = y;
		y = (x + n / x) / 2;
	}
	return (x);
}

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

static void	push_chunk(t_list **a, t_list **b, int cmin, int cmax, int is_last)
{
	int	size_a;
	int	rotations;
	int	val;

	size_a = ft_lstsize(*a);
	rotations = 0;
	while (*a && rotations < size_a)
	{
		val = *(int *)(*a)->content;
		if (val >= cmin && (is_last || val < cmax))
		{
			push(a, b);
			rotations = 0;
			size_a--;
		}
		else
		{
			rotate(a);
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

void	chunck(t_list **a, t_list **b)
{
	int	num_chunks;
	int	min_val;
	int	max_val;
	int	chunk;

	get_minmax(*a, &min_val, &max_val);
	num_chunks = get_num_chunks(*a);
	chunk = 0;
	while (chunk < num_chunks)
	{
		push_chunk(a, b,
			min_val + chunk * (max_val - min_val) / num_chunks,
			min_val + (chunk + 1) * (max_val - min_val) / num_chunks,
			chunk == num_chunks - 1);
		chunk++;
	}
}

void	sort_meduim(t_list **a, t_list **b)
{
	while (*b)
	{
		bring_max_to_top(b);
		push(b, a);
	}
}
