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

void	middle_sort(t_stack **a, t_stack **b, t_stack *start, int count)
{
	t_stack	*pivot;
	int		i;

	i = count;
	put_first(a, get_next(*a, start), 1, 1);
	while (i--)
		pb(a, b, 0);
	pivot = get_pivot(*b, get_smaller(*b), get_bigger(*b));
	while (*b)
		pa(a, b, 0);
	i = count;
	move_smallers(a, b, pivot, -1);
	put_first(a, get_next(*a, start), 1, 1);
	pa(a, b, 1);
	pivot->right = 1;
	divide_et_impera(a, b, pivot);
 	if (is_order(*a, get_smaller(*a)))
		return ;
	epic_check(a, b);
}

t_stack	*leftover(t_stack **a, t_stack **b, t_stack *first, t_stack *second)
{
	int		distance;

	if (second)
		second = consecutive_numbers(*a, second, 1);
	distance = get_distance(*a, first, second);
	if (distance == 1)
		alone_numbers(get_next(*a, first));
	else if (distance == 2)
		couple_numbers(a, get_next(*a, first));
	else if (distance == 3)
		trio_in_group(a, get_next(*a, first));
	else if (distance == 4)
		four_in_group(a, b, get_next(*a, first));
	else if (distance == 5)
		five_in_group(a, b, get_next(*a, first));
	else if (distance > 5)
		middle_sort(a, b, first, distance);
	return (second);
}

void	epic_check(t_stack **a, t_stack **b)
{
	t_stack	*lst;
	t_stack	*first;

	lst = *a;
	while (lst)
	{
		if (lst->right)
		{
			lst = consecutive_numbers(*a, lst, 0);
			first = lst;
			lst = lst->next;
			while (lst)
			{
				if (!lst->next || lst->right)
				{//4 5 2 8 9 10 7
				//problemi, prima meta' ordinata, seconda tutto ok tranne l'ultimo numero, non parte il sort
 					if (!lst->next && !lst->right)
						lst = NULL;
					lst = leftover(a, b, first, lst);
					if (!lst)
						lst = bfrthis(*a, lst);
					break ;
				}
				lst = lst->next;
			}
		}
		else
			lst = lst->next;
	}
}

void	sort(t_stack **a, t_stack **b)
{
	t_stack	*pivot;

	pivot = get_pivot(*a, get_smaller(*a), get_bigger(*a));
	move_smallers(a, b, pivot, -1);
	pa(a, b, 1);
	pivot->right = 1;
	divide_et_impera(a, b, pivot);
 	if (is_order(*a, get_smaller(*a)))
		return ;
	epic_check(a, b);
}
