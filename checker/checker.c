#include "checker.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

char	**add_to_arr(char **arr, char *el)
{
	char	**new_arr;
	int		size;

	size = 0;
	while (arr[size])
		size++;
	new_arr = malloc(sizeof(char **) * (size + 2));
	size = 0;
	while (arr[size])
	{
		new_arr[size] = ft_strdup(arr[size]);
		free(arr[size++]);
	}
	if (arr)
		free(arr);
	new_arr[size++] = ft_strdup(el);
	new_arr[size] = 0;
	return (new_arr)
}

void	choose_instruction(char **instractions, char *instraction)
{
	if (ft_strncmp(instruction, "pa", 2))
		pa(&a, &b, 0);
	else if (ft_strncmp(instruction, "pb", 2))
		pb(&a, &b, 0);
	else if (ft_strncmp(instruction, "sa", 2))
		sa(&a, 0);
	else if (ft_strncmp(instruction, "sb", 2))
		sb(&b, 0);
	else if (ft_strncmp(instruction, "ss", 2))
		ss(&a, &b, 0);
	else if (ft_strncmp(instruction, "ra", 2))
		ra(&a, 0);
	else if (ft_strncmp(instruction, "rb", 2))
		rb(&b, 0);
	else if (ft_strncmp(instruction, "rr", 2))
		rr(&a, &b, 0);
	else if (ft_strncmp(instruction, "rra", 3))
		rra(&a, 0);
	else if (ft_strncmp(instruction, "rrb", 3))
		rrb(&b, 0);
	else if (ft_strncmp(instruction, "rrr", 3))
		rrr(&a, &b, 0);
	else
	{
		write(2, "Error\n", 6);
		free_arr(instractions);
		return (0);
	}
}

int	main(int argc, char *argv[])
{
	t_stack *a;
	t_stack *b;
	int		i;
	char	*line;
	char	**instructions

	if (argc < 2)
		return (0);
	a = manage_input(argv);
	if (!a)
		return (0);
	line = get_next_line(0);
	instructions = add_to_arr(instructions, line);
	while (line)
	{
		line = get_next_line(0);
		instructions = add_to_arr(instructions, line);
	}
	i = 0;
	while (instructions[i])
		choose_instruction(instructions, instructions[i++]);
	if (b || !is_order(a))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	free_arr(instructions);
	return (0);
}