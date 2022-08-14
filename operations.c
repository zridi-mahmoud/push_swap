/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzridi <mzridi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 22:36:19 by mzridi            #+#    #+#             */
/*   Updated: 2022/08/14 22:16:04 by mzridi           ###   ########.fr       */
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

	two_up = max(stacks->size_a - i - 1, stacks->size_b - j - 1);
	two_dwn = max(i + 1, j + 1);
	up_dwn = stacks->size_a - i - 1 + j + 1;
	dwn_up = i + 1 + stacks->size_b - j - 1;
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
	stacks->target_a = i;
	stacks->target_b = j;
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
	*min_op = 1000000;
	while (i < stacks->size_a)
	{
		j = 0;
		while (j < stacks->size_b)
		{
			jj = j + 1;
			if (jj == stacks->size_b)
				jj = 0;
			if ((stacks->a[i] < stacks->b[j] && stacks->a[i] > stacks->b[jj] && stacks->b[jj] < stacks->b[j]) \
			|| (stacks->a[i] > stacks->b[j] && stacks->a[i] < stacks->b[jj] && stacks->b[jj] > stacks->b[jj]) \
			|| (stacks->a[i] > stacks->max_b && stacks->b[jj] == stacks->max_b) \
			|| (stacks->a[i] < stacks->min_b && stacks->b[jj] == stacks->min_b))
			{
				stacks->min_operations[i] = up_or_down(i, j, stacks, 0);
				if (i == 0 || *min_op > stacks->min_operations[i])
					set_min_operations(stacks, min_op, i, j);
				break ;
			}
			j++;
		}
		i++;
	}
}

int	push_it_to_b(t_stacks *stacks)
{
	int	type;

	type = up_or_down(stacks->target_a, stacks->target_b, stacks, 1);
	// printf("type :%d \n", type);
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
	pa(stacks, 0);
	return (1);
}
