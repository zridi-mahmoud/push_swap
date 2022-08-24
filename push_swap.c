/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzridi <mzridi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:23:46 by mzridi            #+#    #+#             */
/*   Updated: 2022/08/24 23:08:58 by mzridi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(t_stacks *stacks)
{
	if (stacks->size_a <= 3 && stacks->size_a > 1)
		sort_three(stacks);
	else if (stacks->size_a <= 5)
		sort_five(stacks);
	else if (!push_lis(stacks))
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
	if (stacks->size_a > 3)
		rotate_a(stacks);
	return (1);
}

int	main(int argc, char **argv)
{
	int			len;
	int			*int_tab;
	t_stacks	*stacks;

	if (argc == 1)
		return (0);
	int_tab = 0;
	len = get_inp(argv, &int_tab);
	if (!len)
		return (printf("Error\n"), 1);
	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (!stacks)
		return (printf("Error\n"), 1);
	if (!init_stacks(stacks, len, int_tab))
		return (printf("Error\n"), 1);
	if (push_swap(stacks))
		compress(0, 0, ft_split(stacks->operations, ' '));
	free_stack(stacks);
	return (0);
}
