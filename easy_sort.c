/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaiazzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:41:39 by scaiazzo          #+#    #+#             */
/*   Updated: 2023/02/14 11:41:43 by scaiazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	order_trio(t_stack **lst)
{
	int	big_pos;
	int	small_pos;

	big_pos = lstposition(*lst, get_bigger(*lst));
	small_pos = lstposition(*lst, get_smaller(*lst));
	if (big_pos + small_pos == 1)
	{
		if (big_pos > small_pos)
			sa(lst, 1);
		ra(lst, 1);
	}
	else if (big_pos + small_pos == 2)
	{
		if (big_pos < small_pos)
		{
			sa(lst, 1);
			rra(lst, 1);
		}
	}
	else if (big_pos + small_pos == 3)
	{
		if (big_pos > small_pos)
			sa(lst, 1);
		else
			rra(lst, 1);
	}
}

void	order_four(t_stack **A, t_stack **B)
{
	int	big_weight;
	int	small_weight;

	big_weight = ft_abs(2 - lstposition(*A, get_bigger(*A))) - 1;
	small_weight = ft_abs(2 - lstposition(*A, get_smaller(*A)));
	if (big_weight > small_weight)
		move_to_b(A, B, get_bigger(*A), 1);
	else
		move_to_b(A, B, get_smaller(*A), 1);
	order_trio(A);
	pa(A, B, 1);
	if (big_weight > small_weight)
		ra(A, 1);
}

void	order_five(t_stack **A, t_stack **B)
{
	move_to_b(A, B, get_smaller(*A), 1);
	move_to_b(A, B, get_smaller(*A), 1);
	order_trio(A);
	pa(A, B, 1);
	pa(A, B, 1);
}
