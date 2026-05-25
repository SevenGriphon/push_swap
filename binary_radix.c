#include "push_swap.h"

int op_count = 0;

int ft_log(unsigned int base, int n)
{
    int result;
    unsigned int nb;

    if (n < 0)
    {
        nb = n * -1;
    }
    else
    {
        nb = n;
    }
    result = 0;
    while (nb > base)
    {
        nb /= base;
        result++;
    }
    return(result + 1);
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

int ft_pow(int base, int exponent)
{
    int result;

    result = 1;
    while (exponent != 0)
    {
        result *= base;
        exponent--;
    }
    return (result);
}

int get_binary_digit(int n, int pos)
{
    n = n/ft_pow(2, pos);
    if (n < 0)
    {
        n *= -1;
    }
    return (n % 2);
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

void sort_by_digit(t_list **a, t_list **b, int pos)
{
    int i;
    int size;
    int digit;
    int reverse;

    if (!needs_sorting(*a, pos))
    {
        return ;
    }
    reverse = needs_reverse_sort(*a, pos);
    size = ft_lstsize(*a);
    i = 0;
    while (i != size)
    {
        digit = get_binary_digit(*(int *)((*a)->content), pos);
        if ((!reverse && digit == 0) || (reverse && digit == 1))
        {
            op_count++;
            push(a, b);
        }
        else
        {
            op_count++;
            rotate(a);
        }
        i++;
    }
    i = 0;
    while (*b != NULL)
    {
        op_count++;
        push(b, a);
        i++;
    }
    if (reverse)
    {
        while (i != 0)
        {
            op_count++;
            rotate(a);
            i--;
        }
    }
}

void sort_by_sign(t_list **a, t_list **b)
{
    int i;
    int size;
    int number;

    size = ft_lstsize(*a);
    i = 0;
    while (i != size)
    {
        number = *(int *)((*a)->content);
        if (number < 0)
        {
            op_count++;
            push(a, b);
        }
        else
        {
            op_count++;
            rotate(a);
        }
        i++;
    }
    i = 0;
    while (*b != NULL)
    {
        op_count++;
        op_count++;
        rotate(b);
        push(b, a);
        i++;
    }
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

void radix(t_list **a, t_list **b)
{
    int max_size;
    int i;

    max_size = find_longest(*a);
    i = 0;
    while (i != max_size)
    {
        sort_by_digit(a, b, i);
        print_sorted_part(*a, i);
        i++;
    }

    sort_by_sign(a, b);
    print_sorted_part(*a, i);
    printf("%i\n", op_count);
}