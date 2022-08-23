/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzridi <mzridi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 16:39:40 by mzridi            #+#    #+#             */
/*   Updated: 2022/08/23 18:15:50 by mzridi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_max_min(t_stacks *stacks, int n)
{
	if (n > stacks->max_a)
		stacks->max_a = n;
	if (n < stacks->min_a)
		stacks->min_a = n;
}

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

void	pa(t_stacks *stacks)
{
	int	tmp;
	int	i;

	save_op(stacks, "pa ");
	tmp = stacks->b[0];
	check_max_min(stacks, tmp);
	stacks->size_a += 1;
	i = stacks->size_a;
	while (--i > 0)
		stacks->a[i] = stacks->a[i - 1];
	stacks->a[0] = tmp;
	ra(stacks, 0, 0);
	stacks->size_b -= 1;
}

void	pb(t_stacks *stacks)
{
	int	tmp;
	int	i;

	save_op(stacks, "pb ");
	tmp = stacks->a[0];
	stacks->size_b += 1;
	i = stacks->size_b;
	while (--i > 0)
		stacks->b[i] = stacks->b[i - 1];
	stacks->b[0] = tmp;
	ra(stacks, 1, 0);
	stacks->size_a -= 1;
}
