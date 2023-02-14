/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_in_group.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaiazzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:40:03 by scaiazzo          #+#    #+#             */
/*   Updated: 2023/02/14 11:40:06 by scaiazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_stack	*trio_in_group(t_stack **lst, t_stack *trio)
{
	t_stack	*bigger;
	t_stack	*smaller;
	int		big_pos;
	int		small_pos;

	put_first(lst, trio, 1);
	if (trio->x > get_next(*lst, trio)->x)
	{
		bigger = trio;
		smaller = get_next(*lst, trio);
		if (trio->x > get_next(*lst, get_next(*lst, trio))->x)
		{
			if (get_next(*lst, trio)->x > get_next(*lst, get_next(*lst, trio))->x)
				smaller = get_next(*lst, get_next(*lst, trio));
		}
		else
			bigger = get_next(*lst, get_next(*lst, trio));
	}
	else
	{
		bigger = get_next(*lst, trio);
		smaller = trio;
		if (get_next(*lst, trio)->x > get_next(*lst, get_next(*lst, trio))->x)
		{
			if (trio->x > get_next(*lst, get_next(*lst, trio))->x)
				smaller = get_next(*lst, get_next(*lst, trio));
		}
		else
			bigger = get_next(*lst, get_next(*lst, trio));
	}
	big_pos = lstposition(*lst, bigger);
	small_pos = lstposition(*lst, smaller);
	if (big_pos + small_pos == 1)
	{
		if (big_pos < small_pos)
			sa(lst, 1);
		ra(lst, 1);
		sa(lst, 1);
	}
	else if (big_pos + small_pos == 2)
	{
		if (big_pos < small_pos)
		{
			sa(lst, 1);
			ra(lst, 1);
			sa(lst, 1);
			rra(lst, 1);
			sa(lst, 1);
		}
	}
	else if (big_pos + small_pos == 3)
	{
		if (big_pos < small_pos)
		{
			ra(lst, 1);
			sa(lst, 1);
			rra(lst, 1);
		}
		sa(lst, 1);
	}
	smaller->right = 1;
	get_next(*lst, smaller)->right = 1;
	get_next(*lst, get_next(*lst, smaller))->right = 1;
	return (smaller);
}

void	four_in_group(t_stack **A, t_stack **B, t_stack *four)
{
	int		big_weight;
	int		small_weight;
	t_stack	*bigger;
	t_stack	*smaller;

	put_first(A, four, 1);
	pb(A, B, 0);
	pb(A, B, 0);
	pb(A, B, 0);
	pb(A, B, 0);
	bigger = get_bigger(*B);
	smaller = get_smaller(*B);
	pa(A, B, 0);
	pa(A, B, 0);
	pa(A, B, 0);
	pa(A, B, 0);
	big_weight = lstposition(*A, bigger) + 3;
	small_weight = lstposition(*A, smaller);
	if (small_weight == 0 || big_weight - 3 == 0)
		four = four->next;
	if (big_weight < small_weight)
		move_to_b(A, B, bigger, 1);
	else
		move_to_b(A, B, smaller, 1);
	four = trio_in_group(A, four);
	if (big_weight < small_weight)
		put_first(A, get_next(*A, get_next(*A, get_next(*A, four))), 1);
	else
		put_first(A, four, 1);
	pa(A, B, 1);
	smaller->right = 1;
	bigger->right = 1;
}

void	five_in_group(t_stack **A, t_stack **B, t_stack *five)
{
	t_stack	*smaller1;
	t_stack	*smaller2;

	put_first(A, five, 1);
	pb(A, B, 0);
	pb(A, B, 0);
	pb(A, B, 0);
	pb(A, B, 0);
	pb(A, B, 0);
	smaller1 = get_smaller(*B);
	move_to_a(A, B, smaller1, 0);
	smaller2 = get_smaller(*B);
	move_to_b(A, B, smaller1, 0);
	put_first(B, get_next(*B, five), 0);
	pa(A, B, 0);
	pa(A, B, 0);
	pa(A, B, 0);
	pa(A, B, 0);
	pa(A, B, 0);
	while (five == smaller1 || five == smaller2)
		five = five->next;
	move_to_b(A, B, smaller1, 1);
	move_to_b(A, B, smaller2, 1);
	ft_printf("five %d\n", five->x);
	five = trio_in_group(A, five);
	put_first(A, five, 1);
	pa(A, B, 1);
	pa(A, B, 1);
	smaller1->right = 1;
	smaller2->right = 1;
}
