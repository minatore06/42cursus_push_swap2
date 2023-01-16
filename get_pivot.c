/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaiazzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:44:04 by scaiazzo          #+#    #+#             */
/*   Updated: 2023/01/12 13:44:16 by scaiazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_stack    *get_pivot(t_stack *start)
{
    t_stack *pivot;
    int     i;

    i = ft_lstsize(start) / 2;
    pivot = start;
    while (i > 0)
    {
        pivot = pivot->next;
        i--;
    }
    if (pivot->x > start->x)
    {
        if (pivot->x < ft_lstlast(start)->x)
            return (pivot);
        else if (start->x < ft_lstlast(start)->x)
            return (ft_lstlast(start));
        else
            return (start);
    }
    else if (pivot->x > ft_lstlast(start)->x)
            return (pivot);
    else if (start->x > ft_lstlast(start)->x)
        return (ft_lstlast(start));
    else
        return (start);
}