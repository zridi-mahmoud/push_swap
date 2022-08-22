/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzridi <mzridi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 22:36:19 by mzridi            #+#    #+#             */
/*   Updated: 2022/08/22 23:46:53 by mzridi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	up_or_down(int i, int j, t_stacks *stacks)
{
	int	two_up;
	int	two_dwn;
	int	up_dwn;
	int	dwn_up;

	two_up = max(i, j);
	two_dwn = max(stacks->size_a - i, stacks->size_b - j);
	up_dwn = i + stacks->size_b - j;
	dwn_up = stacks->size_a - i + j;
	if (two_up <= two_dwn && two_up <= up_dwn && two_up <= dwn_up)
		return (two_up);
	if (two_dwn <= two_up && two_dwn <= up_dwn && two_dwn <= dwn_up)
		return (two_dwn);
	if (up_dwn <= two_up && up_dwn <= two_dwn && up_dwn <= dwn_up)
		return (up_dwn);
	if (dwn_up <= two_up && dwn_up <= two_dwn && dwn_up <= up_dwn)
		return (dwn_up);
	else
		return (0);
}

int	up_or_down_type(int i, int j, t_stacks *stacks)
{
	int	two_up;
	int	two_dwn;
	int	up_dwn;
	int	dwn_up;

	two_up = max(i, j);
	two_dwn = max(stacks->size_a - i, stacks->size_b - j);
	up_dwn = i + stacks->size_b - j;
	dwn_up = stacks->size_a - i + j;
	if (two_up <= two_dwn && two_up <= up_dwn && two_up <= dwn_up)
		return (1);
	if (two_dwn <= two_up && two_dwn <= up_dwn && two_dwn <= dwn_up)
		return (2);
	if (up_dwn <= two_up && up_dwn <= two_dwn && up_dwn <= dwn_up)
		return (3);
	if (dwn_up <= two_up && dwn_up <= two_dwn && dwn_up <= up_dwn)
		return (4);
	else
		return (0);
}

void	set_min_operations(t_stacks *stacks, int i, int j)
{
	int	jj;

	while (j < stacks->size_a)
	{
		jj = j - 1;
		if (j == 0)
			jj = stacks->size_a - 1;
		if ((stacks->b[i] < stacks->a[j] && stacks->b[i] > stacks->a[jj] \
		&& stacks->b[i] < stacks->max_a && stacks->b[i] > stacks->min_a) \
		|| (stacks->b[i] > stacks->max_a && stacks->a[j] == stacks->min_a) \
		|| (stacks->b[i] < stacks->min_a && stacks->a[jj] == stacks->max_a))
		{
			if ((up_or_down(stacks->target_a, stacks->target_b, stacks) \
			> up_or_down(j, i, stacks)) || stacks->target_a == -1)
			{
				stacks->target_b = i;
				stacks->target_a = j;
			}
			break ;
		}
		j++;
	}
}

void	get_min_operation(t_stacks *stacks)
{
	int	i;
	int	j;

	i = 0;
	i = 0;
	stacks->target_a = -1;
	while (i < stacks->size_b)
	{
		j = 0;
		set_min_operations(stacks, i, j);
		i++;
	}
}

int	push_it_to_a(t_stacks *stacks)
{
	int	type;

	type = up_or_down_type(stacks->target_a, stacks->target_b, stacks);
	if (type == 1)
		r_up_up(stacks);
	else if (type == 2)
		r_down_down(stacks);
	else if (type == 3)
		r_up_down(stacks);
	else if (type == 4)
		r_down_up(stacks);
	else
		return (1);
	pa(stacks);
	return (1);
}
