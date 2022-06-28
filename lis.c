/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzridi <mzridi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:32:59 by mzridi            #+#    #+#             */
/*   Updated: 2022/06/26 19:05:21 by mzridi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
#include <stdlib.h>

// the longest increasing subsequence 

void	lis(int *arr, int size, int *dp)
{
	int	i;
	int	j;
	int	max;
	int	tmp;

	dp[size - 1] = 1;
	max = 1;
	i = size - 1;
	while (--i >= 0)
	{
		dp[i] = 1;
		j = size - 1;
		while (i < j)
		{
			if (arr[i] < arr[j])
			{
				tmp = dp[j] + 1;
				if (tmp > dp[i])
					dp[i] = tmp;
			}
			j -= 1;
		}
		if (dp[i] > max)
			max = dp[i];
	}
}

int	main(void)
{
	int arr[] = {3, 4, -1, 0, 6, 2, 3, -2, 9, 10};
	int size = 10;
	int *dp = (int *)malloc(sizeof(int) * size);
	lis(arr, size, dp);

	for (int i = 0; i < size; i++)
		printf("%d ", dp[i]);
	printf("\n");
}