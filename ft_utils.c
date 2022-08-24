/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzridi <mzridi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 12:11:03 by mzridi            #+#    #+#             */
/*   Updated: 2022/08/24 23:08:12 by mzridi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_i_j(t_stacks *stacks, int i, int j)
{
	int	tmp;

	tmp = stacks->sorted_a[i];
	stacks->sorted_a[i] = stacks->sorted_a[j];
	stacks->sorted_a[j] = tmp;
}

int	init_stacks_helper(t_stacks *stacks, int size)
{
	int	i;

	stacks->operations = (char *)malloc(sizeof(char) * 1);
	if (!stacks->operations)
	{
		free(stacks->b);
		free(stacks->sorted_a);
		free(stacks);
		return (0);
	}
	stacks->operations[0] = 0;
	stacks->size_a = size;
	stacks->size_b = 0;
	i = -1;
	while (++i < size)
		stacks->sorted_a[i] = stacks->a[i];
	stacks->rotations = 0;
	return (1);
}

int	init_stacks(t_stacks *stacks, int size, int *int_tab)
{
	stacks->a = int_tab;
	stacks->b = (int *)malloc(sizeof(int) * size);
	if (!stacks->b)
		return (0);
	stacks->sorted_a = (int *)malloc(sizeof(int) * size);
	if (!stacks->sorted_a)
	{
		free(stacks->b);
		free(stacks);
		return (0);
	}
	if (!init_stacks_helper(stacks, size))
		return (0);
	return (sorted(stacks));
}

void	push_lis_helper(t_stacks *stacks, int *seq)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (stacks->size_a > stacks->size_seq && i < stacks->size_seq)
	{
		if (seq[i] == stacks->a[0])
		{
			ra(stacks, 1, 1);
			i++;
		}
		else
			pb(stacks);
		j++;
	}
	while (stacks->size_seq < stacks->size_a)
		pb(stacks);
}

int	push_lis(t_stacks *stacks)
{
	int	*dp;
	int	*seq;

	seq = NULL;
	dp = (int *)malloc(sizeof(int) * stacks->size_a);
	if (!dp)
	{
		printf("Error\n");
		return (0);
	}
	seq = lis(stacks, dp, -1e9);
	if (!seq)
	{
		free(dp);
		printf("Error\n");
		return (0);
	}
	push_lis_helper(stacks, seq);
	free(seq);
	free(dp);
	return (1);
}
