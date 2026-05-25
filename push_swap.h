/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alnoviko <alnoviko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 17:55:25 by alnoviko          #+#    #+#             */
/*   Updated: 2026/05/25 17:55:26 by alnoviko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void	swap(t_list **stack);
void	push(t_list **src, t_list **dest);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);

int		ft_len(t_list *pile);
double	compute_disorder(t_list *pile);
void	sort_adaptive(t_list **a, t_list **b);

int		find_max_pos(t_list *b);
void	bring_max_to_top(t_list **b);
void	sort_simple(t_list **a, t_list **b);

int		my_sqrt(int n);
void	chunck(t_list **a, t_list **b);
void	sort_meduim(t_list **a, t_list **b);

int		get_binary_digit(int n, int pos);
int		find_longest(t_list *stack);
int		needs_sorting(t_list *a, int pos);
int		needs_reverse_sort(t_list *a, int pos);
void	print_sorted_part(t_list *stack, int pos);
void	radix(t_list **a, t_list **b);

int		ft_log(unsigned int base, int n);
int		ft_pow(int base, int exponent);

void	print_stack(t_list *stack);
t_list	*create_node(char *arg);

#endif
