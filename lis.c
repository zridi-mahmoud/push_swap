/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzridi <mzridi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:32:59 by mzridi            #+#    #+#             */
/*   Updated: 2022/06/19 18:01:31 by mzridi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
#include <stdlib.h>

int	_lis(int arr[], int n, int *max_ref)
{
	int	res;
	int	max_ending_here;
	int	i;

	if (n == 1)
		return (1);
	max_ending_here = 1;
	i = 1;
	while (i < n)
	{
		res = _lis(arr, i, max_ref);
		if (arr[i - 1] < arr[n - 1]
			&& res + 1 > max_ending_here)
			max_ending_here = res + 1;
		i++;
	}
	if (*max_ref < max_ending_here)
		*max_ref = max_ending_here;
	return (max_ending_here);
}

int	lis(int arr[], int n)
{
	int	max;

	max = 1;
	_lis(arr, n, &max);
	return (max);
}

int main()
{
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("Length of lis is %d", lis(arr, n));
	return 0;
}