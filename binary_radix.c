#include "push_swap.h"

int op_count = 0;

int ft_log(int base, int n)
{
    int result;

    result = 0;
    while (n > base)
    {
        n /= base;
        result++;
    }
    return(result + 1);
}

int find_max(t_list *stack)
{
    int max;

    max = *(int *)(stack->content);
    while (stack)
    {
        if (*(int *)(stack->content) > max)
        {
            max = *(int *)(stack->content);
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
    return (n % 2);
}

void sort_by_digit(t_list **a, t_list **b, int pos)
{
    int i;
    int size;

    size = ft_lstsize(*a);
    i = 0;
    while (i != size)
    {
        if (get_binary_digit(*(int *)((*a)->content), pos) == 0)
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
    while (*b != NULL)
    {
        op_count++;
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

    max_size = ft_log(2, find_max(*a));
    i = 0;
    while (i != max_size)
    {
        sort_by_digit(a, b, i);
        print_sorted_part(*a, i);
        i++;
    }
    printf("%i\n", op_count);
}