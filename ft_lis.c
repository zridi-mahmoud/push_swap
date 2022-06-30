/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzridi <mzridi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:32:59 by mzridi            #+#    #+#             */
/*   Updated: 2022/06/30 21:15:52 by mzridi           ###   ########.fr       */
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

int	*lis(int *arr, int size, int *dp)
{
	int	i;
	int	j;
	int	*seq;
	int	seq_size;

	seq_size = lis_size(arr, size, dp);
	seq = (int *)malloc(sizeof(int) * seq_size);
	if (!seq)
		return (NULL);
	i = 0;
	j = 0;
	while (seq_size > 0)
	{
		if (dp[i] == seq_size)
		{
			seq[j] = arr[i];
			seq_size -= 1;
			j++;
		}
		i++;
	}
	return (seq);
}
