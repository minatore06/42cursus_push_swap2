/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   learn_and_do.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaiazzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:42:34 by scaiazzo          #+#    #+#             */
/*   Updated: 2023/02/28 10:42:37 by scaiazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

int	choose_instruction1(char *instr, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(instr, "pa", 3))
		pa(a, b, 0);
	else if (!ft_strncmp(instr, "pb", 3))
		pb(a, b, 0);
	else if (!ft_strncmp(instr, "sa", 3))
		sa(a, 0);
	else if (!ft_strncmp(instr, "sb", 3))
		sb(b, 0);
	else if (!ft_strncmp(instr, "ss", 3))
		ss(a, b, 0);
	else
		return (1);
	return (0);
}

int	choose_instruction2(char *instr, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(instr, "ra", 3))
		ra(a, 0);
	else if (!ft_strncmp(instr, "rb", 3))
		rb(b, 0);
	else if (!ft_strncmp(instr, "rr", 3))
		rr(a, b, 0);
	else if (!ft_strncmp(instr, "rra", 4))
		rra(a, 0);
	else if (!ft_strncmp(instr, "rrb", 4))
		rrb(b, 0);
	else if (!ft_strncmp(instr, "rrr", 4))
		rrr(a, b, 0);
	else
		return (1);
	return (0);
}

int	choose_instruction(char **insts, char *inst, t_stack **a, t_stack **b)
{
	int	err;

	err = 1;
	if (!ft_strncmp(inst, "", 1))
		return (0);
	if (!ft_strncmp(inst, "p", 1) || !ft_strncmp(inst, "s", 1))
		err = choose_instruction1(inst, a, b);
	else if (!ft_strncmp(inst, "r", 1))
		err = choose_instruction2(inst, a, b);
	if (err)
	{
		write(2, "Error\n", 6);
		free_arr(insts);
		return (1);
	}
	return (0);
}

int	get_instructions_and_exec(t_stack **a, t_stack **b)
{
	char	*line;
	char	**instructions;
	int		i;

	line = get_next_line(0);
	instructions = NULL;
	instructions = add_to_arr(instructions, line);
	free(line);
	while (line)
	{
		line = get_next_line(0);
		if (ft_strlen(line) > 1)
			instructions = add_to_arr(instructions, line);
		free(line);
	}
	i = 0;
	while (instructions[i])
	{
		if (choose_instruction(instructions, instructions[i++], a, b))
			return (1);
	}
	free_arr(instructions);
	return (0);
}
