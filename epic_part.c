/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epic_part.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaiazzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:33:08 by scaiazzo          #+#    #+#             */
/*   Updated: 2023/02/20 16:33:11 by scaiazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	middle_sort(t_stack **A, t_stack **B, t_stack *start, int count)
{
	t_stack *pivot;
	int		i;

	i = count;
	put_first(A, get_next(*A, start), 1, 1);
	while (i--)
		pb(A, B, 0);
	pivot = get_pivot(*B, get_smaller(*B), get_bigger(*B));
	while (*B)
		pa(A, B, 0);
	i = count;
	move_smallers(A, B, pivot, -1);
	put_first(A, get_next(*A, start), 1, 1);
	pa(A, B, 1);
	pivot->right = 1;
	divide_et_impera(A, B, pivot);
	//ft_printf("MEGA\n");
	epic_check(A, B);
}

void	epic_check(t_stack **A, t_stack **B)
{
	t_stack	*lst;
	t_stack	*first;
	t_stack	*second;

	lst = *A;
	while (lst)
	{
		if (lst->right)
		{
			lst = consecutive_numbers(*A, lst, 0);
			first = lst;
			lst = lst->next;
			while (lst)
			{
				if (lst->right)
				{
					second = lst;
					second = consecutive_numbers(*A, second, 1);
					//ft_printf("first %d, second %d\n", first->x, second->x);
					if (get_distance(*A, first, second) == 1){//ft_printf("alone\n");
						alone_numbers(get_next(*A, first));}
					else if (get_distance(*A, first, second) == 2){//ft_printf("couple\n");
						couple_numbers(A, get_next(*A, first));}
					else if (get_distance(*A, first, second) == 3){//ft_printf("trio\n");
						trio_in_group(A, get_next(*A, first));}
					else if (get_distance(*A, first, second) == 4){//ft_printf("quadro\n");
						four_in_group(A, B, get_next(*A, first));}
					else if (get_distance(*A, first, second) == 5){//ft_printf("quinto\n");
						five_in_group(A, B, get_next(*A, first));}
					else if (get_distance(*A, first, second) > 5){//ft_printf("picche\n");
						middle_sort(A, B, first, get_distance(*A, first, second));}
					lst = second;
					break ;
				}
				lst = lst->next;
			}
			//print_stack(*A);
			
		}
		else
			lst = lst->next;
	}
}

//MOVE ALL SMALLER TO B
//MOVE PIVOT TO B
//PUT larger then next pivot
//again
//again
void	sort(t_stack **A, t_stack **B)
{
	t_stack *pivot;
/* 	t_stack	*big_left;
	t_stack	*small_right; */

/* 	if (is_order(A->head, first, last))
		return ; */
	////ft_printf("bfr last %p\n", last);
	pivot = get_pivot(*A, get_smaller(*A), get_bigger(*A));
	//ft_printf("size: %d, pivot %d\n",ft_lstsize(*A), pivot->x);
	move_smallers(A, B, pivot, -1);
	pa(A, B, 1);
	pivot->right = 1;
	divide_et_impera(A, B, pivot);
	//ft_printf("MEGA\n");
	epic_check(A, B);
}
