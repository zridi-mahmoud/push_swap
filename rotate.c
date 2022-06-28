/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzridi <mzridi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 17:55:26 by mzridi            #+#    #+#             */
/*   Updated: 2022/06/26 17:56:06 by mzridi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(int **a, int size_a, int **b, int size_b)
{
	ra(a, size_a);
	ra(b, size_b);
}

void	rra(int **arr, int size)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = *arr[0];
	while (size > 1)
	{
		*arr[size - 2] = *arr[size - 1];
		size -= 1;
	}
	*arr[0] = tmp;
}

void	rrr(int **a, int size_a, int **b, int size_b)
{
	rra(a, size_a);
	rra(b, size_b);
}
