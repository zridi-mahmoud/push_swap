/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzridi <mzridi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:23:46 by mzridi            #+#    #+#             */
/*   Updated: 2022/08/23 21:32:40 by mzridi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	push_swap(t_stacks *stacks)
{
	if (!push_lis(stacks))
	{
		printf("Error\n");
		return (0);
	}
	get_min_max(stacks);
	while (stacks->size_b > 0)
	{
		get_min_operation(stacks);
		if (!push_it_to_a(stacks))
			break ;
	}
	rotate_a(stacks);
	return (1);
}

int	main(int argc, char **argv)
{
	char		**str_tab;
	int			*int_tab;
	char		*str;
	t_stacks	*stacks;

	if (argc == 1)
		return (0);
	str = join_args(argv, 1);
	if (!str)
		return (0);
	str_tab = ft_split(str, ' ');
	free(str);
	int_tab = ft_str_to_int(str_tab);
	free_tab(str_tab);
	if (!int_tab)
		return (1);
	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (!stacks)
		return (0);
	if (!init_stacks(stacks, ft_tab_len(str_tab), int_tab))
		return (printf("Error\n"), 1);
	if (push_swap(stacks))
		compress(0, 0, ft_split(stacks->operations, ' '));
	free_stack(stacks);
	return (0);
}
