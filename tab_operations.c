/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzridi <mzridi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 22:16:28 by mzridi            #+#    #+#             */
/*   Updated: 2022/08/23 21:26:36 by mzridi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	sorted(t_stacks *stacks)
{
	int	i;
	int	j;

	i = -1;
	stacks->max_a = -2147483648;
	stacks->min_a = 2147483647;
	while (++i < stacks->size_a - 1)
	{
		j = i;
		while (++j < stacks->size_a)
		{
			if (stacks->sorted_a[i] > stacks->sorted_a[j])
				swap_i_j(stacks, i, j);
			else if (stacks->sorted_a[i] == stacks->sorted_a[j])
				return (free_stack(stacks), 0);
		}
	}
	return (1);
}

void	get_min_max(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->size_a)
	{
		if (stacks->a[i] > stacks->max_a)
			stacks->max_a = stacks->a[i];
		if (stacks->a[i] < stacks->min_a)
			stacks->min_a = stacks->a[i];
		i++;
	}
}

void	rotate_a(t_stacks *stacks)
{
	int	i;

	i = -1;
	while (++i < stacks->size_a)
		if (stacks->a[i] == stacks->min_a)
			break ;
	if (i <= stacks->size_a / 2)
		while (i--)
			ra(stacks, 1, 1);
	else
		while (i++ < stacks->size_a)
			rra(stacks, 1, 1);
}

int	ft_tab_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	tab_int_len(int *tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
