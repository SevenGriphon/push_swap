#include "push_swap.h"

void init_bench(t_bench *bench)
{
    bench->sa = 0;
    bench->sb = 0;
    bench->ss = 0;
    bench->pa = 0;
    bench->pb = 0;
    bench->ra = 0;
    bench->rb = 0;
    bench->rr = 0;
    bench->rra = 0;
    bench->rrb = 0;
    bench->rrr = 0;
    bench->total_ops = 0;
}
void print_bench(t_bench *bench, double disorder, char *strategy_name)
{
    
}