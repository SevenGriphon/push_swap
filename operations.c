#include "push_swap.h"

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
    printf("hjeifoa-afhiowef-awfiohwfoahiofh-awfoipj");
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
    printf("hjeifoa-afhiowef-awfiohwfoahiofh-awfoipj");
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
    printf("hjeifoa-afhiowef-awfiohwfoahiofh-awfoipj");
}

void reverse_rotate(t_list **stack)
{
    t_list *first;
    t_list *last;
    t_list *pre_last;

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
    printf("hjeifoa-afhiowef-awfiohwfoahiofh-awfoipj");
}