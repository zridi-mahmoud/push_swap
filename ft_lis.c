/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzridi <mzridi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:32:59 by mzridi            #+#    #+#             */
/*   Updated: 2022/08/23 00:17:47 by mzridi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	*lis(t_stacks *stacks, int *dp)
{
	int	i;
	int	j;
	int	*seq;
	int	size_seq;

	size_seq = lis_size(stacks->a, stacks->size_a, dp);
	if (!size_seq)
		return (0);
	stacks->size_seq = size_seq;
	seq = (int *)malloc(sizeof(int) * size_seq);
	if (!seq)
		return (NULL);
	i = 0;
	j = 0;
	int last = -1e9;
	while (size_seq > 0)
	{
		if (dp[i] == size_seq && stacks->a[i] > last)
		{
			seq[j] = stacks->a[i];
			size_seq -= 1;
			j++;
			last = stacks->a[i];
		}
		i++;
	}
	return (seq);
}
