/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzridi <mzridi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 16:39:40 by mzridi            #+#    #+#             */
/*   Updated: 2022/07/02 22:47:53 by mzridi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stacks *stacks, int type, int print)
{
	int	tmp;

	if (type)
	{
		if (print)
			printf("sa\n");
		tmp = stacks->a[0];
		stacks->a[0] = stacks->a[1];
		stacks->a[1] = tmp;
	}
	else
	{
		if (print)
			printf("sb\n");
		tmp = stacks->b[0];
		stacks->b[0] = stacks->b[1];
		stacks->b[1] = tmp;
	}
}

void	ss(t_stacks *stacks)
{
	printf("ss\n");
	sa(stacks, 1, 0);
	sa(stacks, 0, 0);
}

void	pa(t_stacks *stacks, int type)
{
	int	tmp;

	if (type)
	{
		printf("pa\n");
		tmp = stacks->b[stacks->size_b - 1];
		stacks->size_b -= 1;
		stacks->a[stacks->size_a] = tmp;
		stacks->size_a += 1;
	}
	else
	{
		printf("pb\n");
		tmp = stacks->a[stacks->size_a - 1];
		stacks->size_a -= 1;
		stacks->b[stacks->size_b] = tmp;
		stacks->size_b += 1;
	}
}
