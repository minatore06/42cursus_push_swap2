/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epic_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaiazzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:48:32 by scaiazzo          #+#    #+#             */
/*   Updated: 2023/02/14 11:48:34 by scaiazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	is_number_between(t_stack *lst, t_stack *small, t_stack *big)
{
	while (lst)
	{
		if (lst == small || lst == big)
		{
			lst = lst->next;
			continue ;
		}
		if (lst->x > small->x && lst->x < big->x)
			return (1);
		lst = lst->next;
	}
	return (0);
}

void	alone_numbers(t_stack *alone)
{
	alone->right = 1;
}

void	couple_numbers(t_stack **a, t_stack *couple)
{
	couple->right = 1;
	get_next(*a, couple)->right = 1;
	if (couple->x > get_next(*a, couple)->x)
	{
		put_first(a, couple, 1, 1);
		sa(a, 1);
	}
}

t_stack	*consecutive_numbers(t_stack *a, t_stack *el, int sec)
{
	t_stack	*check;
	int		is_num_bet;

	check = el;
	while (check->next)
	{
		is_num_bet = is_number_between(a, check, get_next(a, check));
		if (check->x < get_next(a, check)->x && !is_num_bet)
			get_next(a, check)->right = 1;
		else
			break ;
		check = check->next;
	}
	while (bfrthis(a, el))
	{
		is_num_bet = is_number_between(a, bfrthis(a, el), el);
		if (el->x > bfrthis(a, el)->x && !is_num_bet)
			bfrthis(a, el)->right = 1;
		else
			break ;
		el = bfrthis(a, el);
	}
	if (sec)
		return (el);
	return (check);
}
