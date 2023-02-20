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
t_stack	*get_first_bigger(t_stack *lst, t_stack *start, int pivot);
t_stack	*get_last_smaller(t_stack *lst, t_stack *start, int pivot);
t_stack	*get_smaller(t_stack *A);
t_stack	*get_bigger(t_stack *A);
t_stack	*consecutive_numbers(t_stack *A, t_stack *el, int sec);
int     ft_abs(int	x);
int     to_get_first(t_stack *head, t_stack *el);
int     first_before_last(t_stack *first, t_stack *last);
int     lstposition(t_stack *lst, t_stack *el);
int     get_distance(t_stack *lst, t_stack *first, t_stack *second);
int 	is_order(t_stack *lst, t_stack *start, t_stack *end);
int		is_number_between(t_stack *lst, t_stack *small, t_stack *big);
void    put_first(t_stack **stack, t_stack *el, int verbose, int is_a);
void	move_to_b(t_stack **A, t_stack **B, t_stack *el, int verbose);
void	move_to_a(t_stack **A, t_stack **B, t_stack *el, int verbose);
void	move_smallers(t_stack **A, t_stack **B, t_stack *pivot, int direction);
void	move_largers(t_stack **A, t_stack **B, t_stack *pivot, int direction);
void    divide_et_impera(t_stack **A, t_stack **B, t_stack *pivot);
void	epic_check(t_stack **A, t_stack **B);
void	alone_numbers(t_stack *alone);
void	couple_numbers(t_stack **A, t_stack *couple);
void	order_trio(t_stack **lst);
void	order_four(t_stack **A, t_stack **B);
void	order_five(t_stack **A, t_stack **B);
t_stack	*trio_in_group(t_stack **lst, t_stack *trio);
void	four_in_group(t_stack **A, t_stack **B, t_stack *four);
void	five_in_group(t_stack **A, t_stack **B, t_stack *five);
void	middle_sort(t_stack **A, t_stack **B, t_stack *start, int count);
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

void	print_stack(t_stack *s);
#endif
