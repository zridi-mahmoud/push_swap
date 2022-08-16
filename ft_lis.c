/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzridi <mzridi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:32:59 by mzridi            #+#    #+#             */
/*   Updated: 2022/08/16 22:56:04 by mzridi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
#include <stdlib.h>

// the longest increasing subsequence 

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

	size_seq = lis_size(stacks->a, stacks->size_a, dp);
	stacks->size_seq = size_seq;
	seq = (int *)malloc(sizeof(int) * size_seq);
	if (!seq)
		return (NULL);
	i = 0;
	j = 0;
	while (size_seq > 0)
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
