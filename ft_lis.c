/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzridi <mzridi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:32:59 by mzridi            #+#    #+#             */
/*   Updated: 2022/08/18 22:58:23 by mzridi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
#include <stdlib.h>

int	two_a(t_stacks *s)
{
	int	*a;
	int	i;

	i = 0;
	a = (int *)malloc(sizeof(int) * s->size_a * 2);
	while (i < s->size_a * 2)
	{
		a[i] = s->a[i % s->size_a];
		i++;
	}
	s->two_a = a;
	return (a);
}

int	lis_size(int *arr, int size, int *dp)
{
	int	i;
	int	j;
	int	max;

	dp[size - 1] = 1;
	max = 1;
	i = size - 1;
	while (--i >= 0)
	{
		dp[i] = 1;
		j = size - 1;
		while (i < j)
		{
			if (arr[i] < arr[j] && dp[j] + 1 > dp[i])
				dp[i] = dp[j] + 1;
			j -= 1;
		}
		if (dp[i] > max)
			max = dp[i];
	}
	return (max);
}

int	*lis(t_stacks *stacks, int *dp)
{
	int	i;
	int	j;
	int	*seq;
	int	size_seq;

	size_seq = lis_size(two_a(stacks), stacks->size_a * 2, dp);
	stacks->size_seq = size_seq;
	seq = (int *)malloc(sizeof(int) * size_seq);
	if (!seq)
		return (NULL);
	i = 0;
	j = 0;
	while (size_seq * 2 > 0)
	{
		if (dp[i] == size_seq)
		{
			seq[j] = stacks->a[i];
			size_seq -= 1;
			j++;
		}
		i++;
	}
	return (seq);
}

int	*rot_a(int *a, int size)
{
	int	tmp;
	int	i;

	i = -1;
	tmp = a[0];
	while (++i < size - 1)
		a[i] = a[i + 1];
	a[size - 1] = tmp;
}

void	best_lis(t_stacks *stacks, int *dp)
{
	int	*a;
	int	i;
	int	best;
	int	tmp;

	best = 0;
	stacks->rotations = 0;
	a = (int *)malloc(sizeof(int) * stacks->size_a);
	i = -1;
	while (++i < stacks->size_a)
		a[i] = stacks->a[i];
	i = -1;
	while (++i < stacks->size_a)
	{
		tmp = lis_size(a, stacks->size_a, dp);
		if (tmp > best + i)
		{
			best = tmp;
			stacks->rotations = i;
		}
		rot_a(a, stacks->size_a);
	}
}
