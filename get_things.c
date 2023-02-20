/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_things.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaiazzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:10:42 by scaiazzo          #+#    #+#             */
/*   Updated: 2023/02/20 16:10:44 by scaiazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_stack	*get_first_bigger(t_stack *lst, t_stack *start, int pivot)
{
	int		size;

	size = ft_lstsize(lst);
	while (size--)
	{
		////ft_printf("%d\n", lst->x);
		if (start->x > pivot && !start->right)
			return (start);
		start = get_next(lst, start);
	}
	return (0);
}

t_stack	*get_last_smaller(t_stack *lst, t_stack *start, int pivot)
{
	t_stack	*small;
	int		size;
	int		i;

	size = ft_lstsize(lst) - 1;
	while (size >= 0)
	{
		small = start;
		i = 0;
		while (size - i++)
			small = get_next(lst, small);
		size--;
		if (small->x < pivot && !small->right)
			return (small);
	}
	return (0);
}

t_stack	*get_smaller(t_stack *lst)
{
	t_stack	*min;

	min = lst;
	while (lst)
	{
		if (lst->x < min->x)
			min = lst;
		lst = lst->next;
	}
	return (min);
}

t_stack	*get_bigger(t_stack *lst)
{
	t_stack	*max;

	max = lst;
	while (lst)
	{
		if (lst->x > max->x)
			max = lst;
		lst = lst->next;
	}
	return (max);
}
