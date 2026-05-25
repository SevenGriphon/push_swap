#include "push_swap.h"

int op_count = 0;

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