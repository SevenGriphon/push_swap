#include "push_swap.h"
#include <stdlib.h>

void swap(t_list **stack)
{
    t_list *first;
    t_list *second;

    if (!*stack || !(*stack)->next)
    {
        return ;
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
        return ;
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
    t_list *pre_last;

    first = *stack;
    last = *stack;
    pre_last = NULL;
    while (last->next)
    {
        pre_last = last;
        last = last->next;
    }
    *stack = last;
    if (pre_last)
    {
        pre_last->next = first;
    }
    last->next = first->next;
    first->next = NULL;
}