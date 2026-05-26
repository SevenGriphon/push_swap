/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <alnoviko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 12:00:00 by alnoviko          #+#    #+#             */
/*   Updated: 2026/05/26 12:00:00 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_str(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!s[i] || ft_strlen(s) > 11)
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static long	to_long(char *s)
{
	long	n;
	int		sign;
	int		i;

	n = 0;
	sign = 1;
	i = 0;
	if (s[i] == '-')
		sign = -1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i])
		n = n * 10 + (s[i++] - '0');
	return (n * sign);
}

int	validate_args(int argc, char **argv, int start)
{
	long	n;
	int		i;

	i = start;
	while (i < argc)
	{
		if (!is_valid_str(argv[i]))
			return (0);
		n = to_long(argv[i]);
		if (n < -2147483648L || n > 2147483647L)
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicates(t_list *a)
{
	t_list	*i;
	t_list	*j;

	i = a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (*(int *)i->content == *(int *)j->content)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

int	ft_error(t_list **a)
{
	if (a)
		ft_lstclear(a, free);
	write(2, "Error\n", 6);
	return (1);
}
