/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzridi <mzridi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 22:36:19 by mzridi            #+#    #+#             */
/*   Updated: 2022/08/20 15:04:22 by mzridi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

// type = 0 means return the value of the min operation
// type = 1 means return how to get the value
int	up_or_down(int i, int j, t_stacks *stacks, int type)
{
	int	two_up;
	int	two_dwn;
	int	up_dwn;
	int	dwn_up;

	two_up = max(i, j);
	two_dwn = max(stacks->size_a - i, stacks->size_b - j);
	up_dwn = i + stacks->size_b - j;
	dwn_up = stacks->size_a - i + j;
	if (two_up <= two_dwn && two_up <= up_dwn && two_up <= dwn_up && !type)
		return (two_up);
	if (two_dwn <= two_up && two_dwn <= up_dwn && two_dwn <= dwn_up && !type)
		return (two_dwn);
	if (up_dwn <= two_up && up_dwn <= two_dwn && up_dwn <= dwn_up && !type)
		return (up_dwn);
	if (dwn_up <= two_up && dwn_up <= two_dwn && dwn_up <= up_dwn && !type)
		return (dwn_up);
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

void	set_min_operations(t_stacks *stacks, int *min_op, int i, int j)
{
	*min_op = stacks->min_operations[i];
	stacks->target_b = i;
	stacks->target_a = j;
}

void	get_min_operation(t_stacks *stacks)
{
	int	i;
	int	j;
	int	jj;
	int	*min_op;

	i = 0;
	min_op = malloc(sizeof(int));
	if (!min_op)
		printf("Error while allocating variable");
	*min_op = 1000000000;
	while (i < stacks->size_b)
	{
		j = 0;
		while (j < stacks->size_a)
		{
			jj = j - 1;
			if (j == 0)
				jj = stacks->size_a - 1;
			if ((stacks->b[i] < stacks->a[j] && stacks->b[i] > stacks->a[jj]) \
			|| (stacks->b[i] > stacks->a[jj] && stacks->a[jj] == stacks->max_a) \
			|| (stacks->b[i] < stacks->min_a && stacks->a[j] == stacks->min_a))
			{
				stacks->min_operations[i] = up_or_down(j, i, stacks, 0);
				if (i == 0 || *min_op > stacks->min_operations[i] + i)
					set_min_operations(stacks, min_op, i, j);
				break ;
			}
			else
				stacks->min_operations[i] = 1000000000;
			j++;
		}
		i++;
	}
}

int	push_it_to_a(t_stacks *stacks)
{
	int	type;

	type = up_or_down(stacks->target_a, stacks->target_b, stacks, 1);
	if (type == 1)
		r_up_up(stacks);
	else if (type == 2)
		r_down_down(stacks);
	else if (type == 3)
		r_up_down(stacks);
	else if (type == 4)
		r_down_up(stacks);
	else
	{
		printf("something is wrong");
		return (0);
	}
	pa(stacks);
	return (1);
}
