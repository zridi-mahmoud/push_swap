/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzridi <mzridi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 12:11:03 by mzridi            #+#    #+#             */
/*   Updated: 2022/08/16 23:48:27 by mzridi           ###   ########.fr       */
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
			{
				printf("Error: duplication of %d\n", stacks->sorted_a[i]);
				return (0);
			}
		}
	}
	return (1);
}

int	init_stacks(t_stacks *stacks, int size, int *int_tab)
{
	int	i;

	stacks->a = int_tab;
	stacks->b = (int *)malloc(sizeof(int) * size);
	if (!stacks->b)
		return (0);
	stacks->min_operations = (int *)malloc(sizeof(int) * size);
	if (!stacks->min_operations)
	{
		free(stacks->b);
		return (0);
	}
	i = 1;
	while (i++ < size)
		stacks->min_operations[i] = 1000000000;
	stacks->sorted_a = (int *)malloc(sizeof(int) * size);
	if (!stacks->sorted_a)
	{
		free(stacks->b);
		free(stacks->min_operations);
		return (0);
	}
	stacks->operations = (char *)malloc(sizeof(char) * 1);
	if (!stacks->operations)
	{
		free(stacks->b);
		free(stacks->min_operations);
		free(stacks->sorted_a);
		return (0);
	}
	stacks->operations[0] = 0;
	stacks->size_a = size;
	stacks->size_b = 0;
	i = -1;
	while (++i < size)
		stacks->sorted_a[i] = stacks->a[i];
	return (sorted(stacks));
}

void	push_lis(t_stacks *stacks)
{
	int	*dp;
	int	*seq;
	int	i;

	i = 0;
	seq = NULL;
	dp = (int *)malloc(sizeof(int) * stacks->size_a);
	if (!dp)
	{
		free(seq);
		return ;
	}
	seq = lis(stacks, dp);
	while (stacks->size_seq > i && stacks->size_seq != stacks->size_a)
	{
		if (seq[i] == stacks->a[i])
		{
			ra(stacks, 1, 1);
			stacks->size_seq--;
		}
		else
			pa(stacks, 0);
	}
	free(seq);
	free(dp);
}
