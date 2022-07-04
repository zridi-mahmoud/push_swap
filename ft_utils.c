/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzridi <mzridi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 12:11:03 by mzridi            #+#    #+#             */
/*   Updated: 2022/07/04 22:36:14 by mzridi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_stacks *stacks)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i < stacks->size_a - 1)
	{
		j = i;
		while (++j < stacks->size_a)
		{
			if (stacks->sorted_a[i] > stacks->sorted_a[j])
			{
				tmp = stacks->sorted_a[i];
				stacks->sorted_a[i] = stacks->sorted_a[j];
				stacks->sorted_a[j] = tmp;
			}
			else if (stacks->sorted_a[i] == stacks->sorted_a[j])
			{
				printf("Error: number %d appears more than once\n", \
					stacks->sorted_a[i]);
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
	stacks->sorted_a = (int *)malloc(sizeof(int) * size);
	if (!stacks->sorted_a)
	{
		free(stacks->b);
		free(stacks->min_operations);
		return (0);
	}
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

	seq = NULL;
	dp = (int *)malloc(sizeof(int) * stacks->size_a);
	if (!dp)
	{
		free(seq);
		return ;
	}
	seq = lis(stacks, dp);
	while (stacks->size_seq > 0)
	{
		if (seq[stacks->size_seq - 1] == stacks->a[stacks->size_a - 1])
			pa(stacks, 0 * stacks->size_seq--);
		else
			ra(stacks, 1, 1);
	}
	free(seq);
	free(dp);
	printf("%d %d\n", stacks->size_a, stacks->size_b);
}
