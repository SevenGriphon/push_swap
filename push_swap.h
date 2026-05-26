/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <alnoviko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 17:55:25 by alnoviko          #+#    #+#             */
/*   Updated: 2026/05/26 17:36:24 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_stats
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int strategy;
}	t_stats;

void	swap(t_list **stack);
void	push(t_list **src, t_list **dest);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);

void	do_sa(t_list **a, t_stats *s);
void	do_sb(t_list **b, t_stats *s);
void	do_ss(t_list **a, t_list **b, t_stats *s);

void	do_pa(t_list **a, t_list **b, t_stats *s);
void	do_pb(t_list **a, t_list **b, t_stats *s);

void	do_ra(t_list **a, t_stats *s);
void	do_rb(t_list **b, t_stats *s);
void	do_rr(t_list **a, t_list **b, t_stats *s);

void	do_rra(t_list **a, t_stats *s);
void	do_rrb(t_list **b, t_stats *s);
void	do_rrr(t_list **a, t_list **b, t_stats *s);

void	print_stack(t_list *stack);
t_list	*create_node(char *arg);
void	new_stats(t_stats *stats);

int		ft_len(t_list *pile);
double	compute_disorder(t_list *pile);
void	sort_adaptive(t_list **a, t_list **b, t_stats *stats);
void	print_bench(t_stats *s, double disorder);

int		validate_args(int argc, char **argv, int start);
int		has_duplicates(t_list *a);
int		ft_error(t_list **a);

int		find_max_pos(t_list *b);
void	bring_max_to_top(t_list **b, t_stats *stats);
void	sort_simple(t_list **a, t_list **b, t_stats *stats);

void	chunck(t_list **a, t_list **b, t_stats *stats);
void	sort_meduim(t_list **a, t_list **b, t_stats *stats);

int		get_binary_digit(int n, int pos);
int		find_longest(t_list *stack);
int		needs_sorting(t_list *a, int pos);
int		needs_reverse_sort(t_list *a, int pos);
void	print_sorted_part(t_list *stack, int pos);
void	radix(t_list **a, t_list **b, t_stats *stats);

int		ft_log(unsigned int base, int n);
int		ft_pow(int base, int exponent);
int		my_sqrt(int n);

void	print_stack(t_list *stack);
t_list	*create_node(char *arg);

#endif
