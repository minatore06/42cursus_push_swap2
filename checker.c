/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scaiazzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:35:29 by scaiazzo          #+#    #+#             */
/*   Updated: 2023/02/24 15:35:32 by scaiazzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

char	**add_to_arr(char **arr, char *el)
{
	char	**new_arr;
	int		size;

	size = 0;
	while (arr && arr[size])
		size++;
	new_arr = malloc(sizeof(char **) * (size + 2));
	size = 0;
	while (arr && arr[size])
	{
		new_arr[size] = ft_strdup(arr[size]);
		free(arr[size++]);
	}
	if (arr)
		free(arr);
	new_arr[size++] = ft_strdup(el);
	new_arr[size] = 0;
	return (new_arr);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = manage_input(argv);
	if (!a)
		return (0);
	b = NULL;
	if (get_instructions_and_exec(&a, &b))
	{
		free_stack(a);
		return (0);
	}
	if (b || !is_order(a, a))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	free_stack(a);
	return (0);
}
