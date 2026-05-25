#include "push_swap.h"

void swap(t_list **stack)
{
    t_list *first;
    t_list *second;

    if (!*stack || !(*stack)->next)
    {
        return;
    }
    first = *stack;
    second = (*stack)->next;
    first->next = second->next;
    second->next = first;
    *stack = second;
}

void push(t_list **src, t_list **dest)
{
    t_list *element;

    if (!*src)
    {
        return;
    }
    element = *src;
    *src = (*src)->next;
    element->next = *dest;
    *dest = element;
}

void rotate(t_list **stack)
{
    t_list *first;
    t_list *last;

    first = *stack;
    last = *stack;
    while (last->next)
    {
        last = last->next;
    }
    if (first != last)
    {
        *stack = (*stack)->next;
    }
    last->next = first;
    first->next = NULL;
}

void reverse_rotate(t_list **stack)
{
    t_list *first;
    t_list *last;
    t_list *pre_last;

    pre_last = NULL;
    first = *stack;
    last = *stack;
    while (last->next)
    {
        pre_last = last;
        last = last->next;
    }
    if (pre_last)
    {
        pre_last->next = NULL;
    }
    *stack = last;
    last->next = first;
}

void do_sa(t_list **a, t_stats *s)
{
    swap(a);
    write(1, "sa\n", 3);
    if (s)
        s->sa++;
}

void do_sb(t_list **b, t_stats *s)
{
    swap(b);
    write(1, "sb\n", 3);
    if (s)
        s->sb++;
}

void do_ss(t_list **a, t_list **b, t_stats *s)
{
    swap(a);
    swap(b);
    write(1, "ss\n", 3);
    if (s)
        s->ss++;
}

void do_pa(t_list **a,t_list **b, t_stats *s)
{
    push(b, a);
    write(1, "pa\n", 3);
    if (s)
        s->pa++;
}

void do_pb(t_list **a, t_list **b, t_stats *s)
{
    push(a, b);
    write(1, "pb\n", 3);
    if (s)
        s->pb++;
}

void do_ra(t_list **a,t_stats *s)
{
    rotate(a);
    write(1, "ra\n", 3);
    if (s)
        s->ra++;
}

void do_rb(t_list **b,t_stats *s)
{
    rotate(b);
    write(1, "rb\n", 3);
    if (s)
        s->rb++;
}

void do_rr(t_list **a, t_list **b, t_stats *s)
{
    rotate(a);
    rotate(b);
    write(1, "rr\n", 3);
    if (s)
        s->rr++;
}

void do_rra(t_list **a,t_stats *s)
{
    reverse_rotate(a);
    write(1, "rra\n", 4);
    if (s)
        s->rra++;
}

void do_rrb(t_list **b,t_stats *s)
{
    reverse_rotate(b);
    write(1, "rrb\n", 4);
    if (s)
        s->rrb++;
}

void do_rrr(t_list **a, t_list **b, t_stats *s)
{
    reverse_rotate(a);
    reverse_rotate(b);
    write(1, "rrr\n", 4);
    if (s)
        s->rrr++;
}