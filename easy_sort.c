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
			sa(lst, 1);
		if (big_pos < small_pos)
			rra(lst, 1);
	}
	else if (big_pos + small_pos == 3)
	{
		if (big_pos > small_pos)
			sa(lst, 1);
		else
			rra(lst, 1);
	}
}

void	order_four(t_stack **a, t_stack **b)
{
	int	big_weight;
	int	small_weight;

	big_weight = ft_abs(2 - lstposition(*a, get_bigger(*a))) - 1;
	small_weight = ft_abs(2 - lstposition(*a, get_smaller(*a)));
	if (big_weight > small_weight)
		move_to_b(a, b, get_bigger(*a), 1);
	else
		move_to_b(a, b, get_smaller(*a), 1);
	order_trio(a);
	pa(a, b, 1);
	if (big_weight > small_weight)
		ra(a, 1);
}

void	order_five(t_stack **a, t_stack **b)
{
	move_to_b(a, b, get_smaller(*a), 1);
	move_to_b(a, b, get_smaller(*a), 1);
	order_trio(a);
	pa(a, b, 1);
	pa(a, b, 1);
}
