#include "push_swap.h"

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

void sort_by_digit(t_list **src, t_list **dest, int pos)
{
    int i;
    int size;

    size = ft_lstsize(*src);
    i = 0;
    // printf("before:\n");
    // print_stack(*src);
    // print_stack(*dest);
    // printf("Should be in dist:\n");
    while (i != size)
    {
        if (get_binary_digit(*(int *)((*src)->content), pos) == 0)
        {
            push(src, dest);
            rotate(dest);
        }
        else
        {
            // printf("%i\n", *(int *)((*src)->content));
            rotate(src);
        }
        i++;
    }
    printf("source: ");
    print_stack(*src);
    printf("destination: ");
    print_stack(*dest);
    while (*src != NULL)
    {
        push(src, dest);
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
        // printf("pass %i\n", i);
        if (i % 2 == 0)
        {
            sort_by_digit(a, b, i);
            print_sorted_part(*b, i);
        }
        else
        {
            sort_by_digit(b, a, i);
            print_sorted_part(*a, i);
        }
        i++;
    }
}