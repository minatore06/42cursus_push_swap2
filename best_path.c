/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaiazzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:02:32 by scaiazzo          #+#    #+#             */
/*   Updated: 2023/01/13 17:03:07 by scaiazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	get_distance(t_stack *lst, t_stack *first, t_stack *second)
{
	int	i;

	if (first_before_last(first, second))
		i = ft_lstsize(first) - ft_lstsize(second);
	else
		i = ft_lstsize(first) - lstposition(lst, second);
	return (i - 1);
}

int	lstposition(t_stack *lst, t_stack *el)
{
	int	i;

	i = 0;
	while (el != lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

//1 up -1 down
int	to_get_first(t_stack *head, t_stack *el)
{
	int	x;

	x = lstposition(head, el) + 1;
	if (x <= ft_lstsize(head) / 2 + 1)
		return (1);
	return (-1);
}

void	put_first(t_stack **stack, t_stack *el, int verbose, int is_a)
{
	int	x;

	x = lstposition(*stack, el);
	if (to_get_first(*stack, el) > 0)
	{
		while (x--)
		{
			if (is_a)
				ra(stack, verbose);
			else
				rb(stack, verbose);
		}
	}
	else
	{
		while (x++ < ft_lstsize(*stack))
		{
			if (is_a)
				rra(stack, verbose);
			else
				rrb(stack, verbose);
		}
	}
}
/* 
void	put_first_test(t_stack **a, t_stack **b, t_stack *el)
{
	int x;

	x = lstposition(*a, el);
	if (to_get_first(*a, el) > 0)
	{
		while (x--)
			rr(a, b);
	}
	else
	{
		while (x++ < ft_lstsize(*a))
			rrr(a, b);
	}
} */