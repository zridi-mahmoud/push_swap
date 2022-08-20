/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzridi <mzridi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:32:59 by mzridi            #+#    #+#             */
/*   Updated: 2022/08/20 14:45:52 by mzridi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
#include <stdlib.h>

int	*two_a(t_stacks *s)
{
	int	*a;
	int	i;

	i = s->size_a;
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

void	rot_a(int *a, int size)
{
	int	tmp;
	int	i;

	i = -1;
	tmp = a[0];
	while (++i < size - 1)
		a[i] = a[i + 1];
	a[size - 1] = tmp;
}

int	*copy(int *t, int size)
{
	int	*t_c;

	t_c = (int *)malloc(sizeof(int) * size);
	if (!t_c)
	{
		free(t_c);
		return (NULL);
	}
	while (--size >= 0)
		t_c[size] = t[size];
	return (t_c);
}

int	best_lis(t_stacks *stacks, int *dp)
{
	int	*a;
	int	i;
	int	best;
	int	tmp;
	int	swiitch;
	int	*v_a;

	v_a = copy(stacks->a, stacks->size_a);
	swiitch = 0;
	stacks->rotations = 0;
	a = (int *)malloc(sizeof(int) * stacks->size_a);
	i = -1;
	best = lis_size(v_a, stacks->size_a, dp);
	while (++i < stacks->size_a)
	{
		if (swiitch)
		{
			tmp = lis_size(v_a, stacks->size_a, dp);
			if (tmp > best + i / 4)
			{
				best = tmp;
				stacks->rotations = i;
				swiitch = 0;
			}
		}
		else
		{
			tmp = lis_size(v_a, stacks->size_a, a);
			if (tmp > best + i)
			{
				best = tmp;
				stacks->rotations = i;
				swiitch = 1;
			}
		}
		rot_a(v_a, stacks->size_a);
	}
	if (swiitch)
	{
		free(dp);
		dp = a;
	}
	if (stacks->rotations < stacks->size_a / 2)
		while (stacks->rotations--)
			ra(stacks, 1, 0);
	else
		while (stacks->rotations++ > stacks->size_a)
			ra(stacks, 0, 0);
	return (best);
}

int	*lis(t_stacks *stacks, int *dp)
{
	int	i;
	int	j;
	int	*seq;
	int	size_seq;

	// size_seq = lis_size(stacks->a, stacks->size_a, dp);
	size_seq = best_lis(stacks, dp);
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
