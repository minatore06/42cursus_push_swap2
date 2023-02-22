#include "push_swap.h"

void    divide_et_impera(t_stack **a, t_stack **b, t_stack *pivot)
{
    while (1)
	{
		if (!*b)
			return ;
		if (ft_lstsize(*b) == 1)
		{
			pa(a, b, 1);
			(*a)->right = 1;
			break;
		}
		else if (ft_lstsize(*b) == 2)
		{
			if ((*b)->x < get_next(*b, *b)->x)
				sb(b, 1);
			pa(a, b, 1);
			(*a)->right = 1;
			pa(a, b, 1);
			(*a)->right = 1;
			break;
		}
		pivot = get_pivot(*b, get_smaller(*b), get_bigger(*b));
		move_largers(a, b, pivot, 1);
		print_stack(*a);
	}
}