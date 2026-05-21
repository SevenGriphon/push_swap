#include "push_swap.h"

void print_stack(t_list *stack)
{
    while (stack)
    {
        printf("%i", *(int *)(stack->content));
        if (stack->next)
        {
            printf(" > ");
        }
        stack = stack->next;
    }
    printf("\n");
}

t_list *create_node(char *arg)
{
    int *value;
    t_list *node;

    value = malloc(sizeof(int));
    *value = ft_atoi(arg);
    node = ft_lstnew(value);
    return (node);
}

int main(int argc, char **argv)
{
    int i;
    t_list *a;

    if (argc < 2)
    {
        return (0);
    }

    i = 1;
    a = create_node(argv[i]);
    i++;
    while (i < argc)
    {
        ft_lstadd_back(&a, create_node(argv[i]));
        i++;
    }
    print_stack(a);
}