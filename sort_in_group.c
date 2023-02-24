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

void	get_small_big(t_stack **lst, t_stack *tri, t_stack **sml, t_stack **bg)
{
	if (tri->x > get_next(*lst, tri)->x)
	{
		*bg = tri;
		*sml = get_next(*lst, tri);
		if (tri->x > get_next(*lst, *sml)->x)
		{
			if ((*sml)->x > get_next(*lst, *sml)->x)
				*sml = get_next(*lst, *sml);
		}
		else
			*bg = get_next(*lst, *sml);
	}
	else
	{
		*bg = get_next(*lst, tri);
		*sml = tri;
		if ((*bg)->x > get_next(*lst, *bg)->x)
		{
			if (tri->x > get_next(*lst, *bg)->x)
				*sml = get_next(*lst, *bg);
		}
		else
			*bg = get_next(*lst, *bg);
	}
}

void	do_the_magic(t_stack **lst, int small_pos, int big_pos)
{
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
}

t_stack	*trio_in_group(t_stack **lst, t_stack *trio)
{
	t_stack	*bigger;
	t_stack	*smaller;
	int		big_pos;
	int		small_pos;

	put_first(lst, trio, 1, 1);
	get_small_big(lst, trio, &smaller, &bigger);
	big_pos = lstposition(*lst, bigger);
	small_pos = lstposition(*lst, smaller);
	do_the_magic(lst, small_pos, big_pos);
	smaller->right = 1;
	get_next(*lst, smaller)->right = 1;
	get_next(*lst, get_next(*lst, smaller))->right = 1;
	return (smaller);
}

void	four_in_group(t_stack **a, t_stack **b, t_stack *four)
{
	int		big_weight;
	int		small_weight;
	t_stack	*bigger;
	t_stack	*smaller;

	put_first(a, four, 1, 1);
	pb(a, b, 0);
	pb(a, b, 0);
	pb(a, b, 0);
	pb(a, b, 0);
	bigger = get_bigger(*b);
	smaller = get_smaller(*b);
	pa(a, b, 0);
	pa(a, b, 0);
	pa(a, b, 0);
	pa(a, b, 0);
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

void	five_in_group(t_stack **a, t_stack **b, t_stack *five)
{
	t_stack	*smaller1;
	t_stack	*smaller2;

	put_first(a, five, 1, 1);
	pb(a, b, 0);
	pb(a, b, 0);
	pb(a, b, 0);
	pb(a, b, 0);
	pb(a, b, 0);
	smaller1 = get_smaller(*b);
	move_to_a(a, b, smaller1, 0);
	smaller2 = get_smaller(*b);
	move_to_b(a, b, smaller1, 0);
	put_first(b, get_next(*b, five), 0, 0);
	pa(a, b, 0);
	pa(a, b, 0);
	pa(a, b, 0);
	pa(a, b, 0);
	pa(a, b, 0);
	while (five == smaller1 || five == smaller2)
		five = five->next;
	move_to_b(a, b, smaller1, 1);
	move_to_b(a, b, smaller2, 1);
	//ft_printf("five %d\n", five->x);
	five = trio_in_group(a, five);
	put_first(a, five, 1, 1);
	pa(a, b, 1);
	pa(a, b, 1);
	smaller1->right = 1;
	smaller2->right = 1;
}
