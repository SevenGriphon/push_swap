#include "push_swap.h"

int get_binary_digit(int n, int pos)
{
    n = n/ft_pow(2, pos);
    if (n < 0)
    {
        n *= -1;
    }
    return (n % 2);
}

int find_longest(t_list *stack)
{
    int max;
    int size;

    max = ft_log(2, *(int *)(stack->content));
    while (stack)
    {
        size = ft_log(2, *(int *)(stack->content));
        if (size > max)
        {
            max = size;
        }
        stack = stack->next;
    }
    return (max);
}

int needs_sorting(t_list *a, int pos)
{
    int digit;

    digit = -1;
    while (a)
    {
        if (digit == -1)
        {
            digit = get_binary_digit(*(int *)(a->content), pos);
        }
        else if (get_binary_digit(*(int *)(a->content), pos) != digit)
        {
            return (1);
        }
        a = a->next;
    }
    return (0);
}

int needs_reverse_sort(t_list *a, int pos)
{
    int ones;
    int zeros;

    ones = 0;
    zeros = 0;
    while (a)
    {
        if (get_binary_digit(*(int *)(a->content), pos) == 1)
        {
            ones++;
        }
        else
        {
            zeros++;
        }
        a = a->next;
    }
    if (ones * 2 < zeros)
    {
        return (1);
    }
    return (0);
}

void print_sorted_part(t_list *stack, int pos)
{
    while (stack)
    {
        printf("%i", *(int *)(stack->content)%ft_pow(2, pos + 1));
        if (stack->next)
        {
            printf(" > ");
        }
        stack = stack->next;
    }
    printf("\n");
}