/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaiazzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:35:55 by scaiazzo          #+#    #+#             */
/*   Updated: 2023/02/24 15:35:58 by scaiazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CHECKER_H
# define CHECKER_H
# include "push_swap.h"

char	**add_to_arr(char **arr, char *el);
int		get_instructions_and_exec(t_stack **a, t_stack **b);
int		choose_instruction(char **insts, char *inst, t_stack **a, t_stack **b);
int		choose_instruction1(char *instr, t_stack **a, t_stack **b);
int		choose_instruction2(char *instr, t_stack **a, t_stack **b);

#endif
