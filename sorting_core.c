#include "push_swap.h"

void    divide_et_impera(t_stack **A, t_stack **B, t_stack *pivot)
{
    while (1)
	{
		if (ft_lstsize(*B) == 1)
		{
			pa(A, B, 1);
			(*A)->right = 1;
			break;
		}
		else if (ft_lstsize(*B) == 2)
		{
			if ((*B)->x < get_next(*B, *B)->x)
				sb(B, 1);
			pa(A, B, 1);
			(*A)->right = 1;
			pa(A, B, 1);
			(*A)->right = 1;
			break;
		}
		pivot = get_pivot(*B, get_smaller(*B), get_bigger(*B));
		move_largers(A, B, pivot, 1);
		//print_stack(*A);
	}
}