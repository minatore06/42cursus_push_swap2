/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four_in_group.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaiazzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:34:23 by scaiazzo          #+#    #+#             */
/*   Updated: 2023/02/24 15:34:25 by scaiazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	get_small_big_qt(t_stack **a, t_stack **b, t_stack **sm, t_stack **bg)
{
	pb(a, b, 0);
	pb(a, b, 0);
	pb(a, b, 0);
	pb(a, b, 0);
	*bg = get_bigger(*b);
	*sm = get_smaller(*b);
	pa(a, b, 0);
	pa(a, b, 0);
	pa(a, b, 0);
	pa(a, b, 0);
}

void	four_in_group(t_stack **a, t_stack **b, t_stack *four)
{
	int		big_weight;
	int		small_weight;
	t_stack	*bigger;
	t_stack	*smaller;

	put_first(a, four, 1, 1);
	get_small_big_qt(a, b, &smaller, &bigger);
	big_weight = lstposition(*a, bigger) + 3;
	small_weight = lstposition(*a, smaller);
	if (big_weight < small_weight && four == bigger)
		four = four->next;
	else if (big_weight >= small_weight && four == smaller)
		four = four->next;
	if (big_weight < small_weight)
		move_to_b(a, b, bigger, 1);
	else
		move_to_b(a, b, smaller, 1);
	four = trio_in_group(a, four);
	if (big_weight < small_weight)
		put_first(a, get_next(*a, get_next(*a, get_next(*a, four))), 1, 1);
	else
		put_first(a, four, 1, 1);
	pa(a, b, 1);
	smaller->right = 1;
	bigger->right = 1;
}
