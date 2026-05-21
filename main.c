#include "push_swap.h"

static int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (ft_isspace(*nptr) == 1)
	{
		nptr++;
	}
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
		{
			sign = -1;
		}
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + *nptr - '0';
		nptr++;
	}
	result *= sign;
	return (result);
}

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

    node = (t_list *)malloc(sizeof(t_list));
    node->next = NULL;
    value = malloc(sizeof(int));
    *value = ft_atoi(arg);
    node->content = value;
    return (node);
}

int main(int argc, char **argv)
{
    int i;
    t_list *a;
    t_list *previous_node;
    t_list *node;

    if (argc < 2)
    {
        return (0);
    }

    i = 1;
    a = create_node(argv[i]);
    previous_node = a;
    i++;
    while (i < argc)
    {
        node = create_node(argv[i]);
        previous_node->next = node;
        previous_node = node;
        i++;
    }
    print_stack(a);
}