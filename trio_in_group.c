/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trio_in_group.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaiazzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:34:14 by scaiazzo          #+#    #+#             */
/*   Updated: 2023/02/24 15:34:16 by scaiazzo         ###   ########.fr       */
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
	else if (big_pos + small_pos == 2 && big_pos < small_pos)
	{
		sa(lst, 1);
		ra(lst, 1);
		sa(lst, 1);
		rra(lst, 1);
		sa(lst, 1);
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
