/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzridi <mzridi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 17:55:26 by mzridi            #+#    #+#             */
/*   Updated: 2022/08/24 23:09:08 by mzridi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stacks *stacks, int type, int print)
{
	int	tmp;
	int	i;

	if (type)
	{
		if (print)
			save_op(stacks, "rra ");
		i = stacks->size_a;
		tmp = stacks->a[stacks->size_a - 1];
		while (--i > 0)
			stacks->a[i] = stacks->a[i - 1];
		stacks->a[0] = tmp;
	}
	else
	{
		if (print)
			save_op(stacks, "rrb ");
		i = stacks->size_b;
		tmp = stacks->b[stacks->size_b - 1];
		while (--i > 0)
			stacks->b[i] = stacks->b[i - 1];
		stacks->b[0] = tmp;
	}
}

void	rr(t_stacks *stacks, int print)
{
	if (print)
		printf("rr\n");
	ra(stacks, 1, 0);
	ra(stacks, 0, 0);
}

void	ra(t_stacks *stacks, int type, int print)
{
	int	tmp;
	int	i;

	if (type)
	{
		if (print)
			save_op(stacks, "ra ");
		i = -1;
		tmp = stacks->a[0];
		while (++i < stacks->size_a - 1)
			stacks->a[i] = stacks->a[i + 1];
		stacks->a[stacks->size_a - 1] = tmp;
	}
	else
	{
		if (print)
			save_op(stacks, "rb ");
		i = -1;
		tmp = stacks->b[0];
		while (++i < stacks->size_b - 1)
			stacks->b[i] = stacks->b[i + 1];
		stacks->b[stacks->size_b - 1] = tmp;
	}
}

void	rrr(t_stacks *stacks, int print)
{
	if (print)
		printf("rrr\n");
	rra(stacks, 1, 0);
	rra(stacks, 0, 0);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
