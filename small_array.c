/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzridi <mzridi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 22:26:16 by mzridi            #+#    #+#             */
/*   Updated: 2022/08/24 22:26:20 by mzridi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(int *a, int size)
{
	int	tmp;
	int	i;

	tmp = -1e9;
	i = -1;
	while (++i < size)
		if (a[i] > tmp)
			tmp = a[i];
	return (tmp);
}

void	sort_three(t_stacks *stacks)
{
	int	max;

	max = get_max(stacks->a, stacks->size_a);
	if (stacks->size_a == 3)
	{
		if (stacks->a[0] == max)
			ra(stacks, 1, 1);
		else if (stacks->a[1] == max)
			rra(stacks, 1, 1);
	}
	if (stacks->a[0] > stacks->a[1])
		sa(stacks, 1, 1);
	else
		return ;
}

void	push(t_stacks *stacks, int i)
{
	int	j;

	j = 0;
	while (j < stacks->size_a && stacks->sorted_a[i] != stacks->a[j])
		j++;
	if (j <= stacks->size_a / 2)
		while (j--)
			ra(stacks, 1, 1);
	else
		while (j++ < stacks->size_a)
			rra(stacks, 1, 1);
	pb(stacks);
}

void	sort_five(t_stacks *stacks)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < stacks->size_a)
	{
		if (stacks->a[j] != stacks->sorted_a[j])
			break ;
		j++;
		if (j == stacks->size_a)
			return ;
	}
	while (stacks->size_a > 3)
		push(stacks, i++);
	sort_three(stacks);
	pa(stacks);
	pa(stacks);
}
