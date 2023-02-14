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

int		is_number_between(t_stack *lst, t_stack *small, t_stack *big)
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

void	couple_numbers(t_stack **A, t_stack *couple)
{
	couple->right = 1;
	get_next(*A, couple)->right = 1;
	if (couple->x > get_next(*A, couple)->x)
	{
		put_first(A, couple, 1, 1);
		sa(A, 1);
	}
}

t_stack	*consecutive_numbers(t_stack *A, t_stack *el, int sec)
{
	t_stack	*check;

	check = el;
	while (check->next)
	{
		if (check->x < get_next(A, check)->x && !is_number_between(A, check, get_next(A, check)))
			get_next(A, check)->right = 1;
		else
			break ;
		check = check->next;
	}
	while (bfrthis(A, el))
	{
		if (el->x > bfrthis(A, el)->x && !is_number_between(A, bfrthis(A, el), el))
			bfrthis(A, el)->right = 1;
		else
			break ;
		el = bfrthis(A, el);
	}
	if (sec)
		return (el);
	return (check);
}
