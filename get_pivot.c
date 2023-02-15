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

int first_before_last(t_stack *first, t_stack *last)
{
    while (first)
    {
        if (first == last)                         
            return (1);
        first = first->next;
    }
    return (0);
}

t_stack    *get_pivot(t_stack *lst, t_stack *small, t_stack *big)
{
    int     med;
    int     distance;
    t_stack *pivot;

    med = (small->x + big->x) / 2;
    distance = med * 2;
    while (lst)
    {

        if (ft_abs(med - lst->x) < distance)
        {
            distance = ft_abs(med - lst->x);
            pivot = lst;
        }
        lst = lst->next;
    }
    return (pivot);
    //ft_printf("str: %d pvt: %d lst: %d\n", first->x, pivot->x, last->x);
}