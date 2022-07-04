/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzridi <mzridi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 17:55:26 by mzridi            #+#    #+#             */
/*   Updated: 2022/07/02 22:56:53 by mzridi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stacks *stacks, int type, int print)
{
	int	tmp;
	int	i;

	if (type)
	{
		if (print)
			printf("ra\n");
		i = stacks->size_a;
		tmp = stacks->a[stacks->size_a - 1];
		while (--i > 0)
			stacks->a[i] = stacks->a[i - 1];
		stacks->a[0] = tmp;
	}
	else
	{
		if (print)
			printf("rb\n");
		i = stacks->size_b;
		tmp = stacks->b[stacks->size_b - 1];
		while (--i > 0)
			stacks->b[i] = stacks->b[i - 1];
		stacks->b[0] = tmp;
	}
}

void	rr(t_stacks *stacks)
{
	printf("rr\n");
	ra(stacks, 1, 0);
	ra(stacks, 0, 0);
}

void	rra(t_stacks *stacks, int type, int print)
{
	int	tmp;
	int	i;

	if (type)
	{
		if (print)
			printf("rra\n");
		i = -1;
		tmp = stacks->a[0];
		while (++i < stacks->size_a - 1)
			stacks->a[i] = stacks->a[i + 1];
		stacks->a[stacks->size_a - 1] = tmp;
	}
	else
	{
		if (print)
			printf("rrb\n");
		i = -1;
		tmp = stacks->b[0];
		while (++i < stacks->size_b - 1)
			stacks->b[i] = stacks->b[i + 1];
		stacks->b[stacks->size_b - 1] = tmp;
	}
}

void	rrr(t_stacks *stacks)
{
	printf("rrr\n");
	rra(stacks, 1, 0);
	rra(stacks, 0, 0);
}
