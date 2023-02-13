/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaiazzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:11:24 by scaiazzo          #+#    #+#             */
/*   Updated: 2023/01/09 16:11:27 by scaiazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct  s_ez_stack
{
    t_stack *head;
    t_stack *start;
}   t_ez_stack;

t_stack *lstlast(t_stack *lst);
t_stack *bfrthis(t_stack *lst, t_stack *this);
t_stack *get_pivot(t_stack *lst, t_stack *start, t_stack *last);
t_stack *get_next(t_stack *A, t_stack *el);
int     to_get_first(t_stack *head, t_stack *el);
int     first_before_last(t_stack *first, t_stack *last);
int     lstposition(t_stack *lst, t_stack *el);
int     get_distance(t_stack *lst, t_stack *first, t_stack *second);
void    put_first(t_stack **stack, t_stack *el, int verbose);
void    pa(t_stack **a, t_stack **b, int verbose);
void    pb(t_stack **a, t_stack **b, int verbose);
void    sa(t_stack **a, int verbose);
void    sb(t_stack **b, int verbose);
void    ss(t_stack **a, t_stack **b);
void    ra(t_stack **a, int verbose);
void    rb(t_stack **b, int verbose);
void    rr(t_stack **a, t_stack **b);
void    rra(t_stack **a, int verbose);
void    rrb(t_stack **b, int verbose);
void    rrr(t_stack **a, t_stack **b);

#endif
