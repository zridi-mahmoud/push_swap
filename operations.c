/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzridi <mzridi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 22:36:19 by mzridi            #+#    #+#             */
/*   Updated: 2022/07/04 22:41:56 by mzridi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	min_operation(int i, int j, t_stacks *stacks)
{
	int	two_up;
	int	two_down;
	int	up_down;
	int	down_up;

	two_up = min(stacks->size_a - i + 1, stacks->size_b - j + 1);
	two_down = min(i + 1, j + 1);
	up_down = stacks->size_a - i + 1 + j + 1;
	down_up = i + 1 + stacks->size_b - j + 1;
	if (two_up <= two_down && two_up <= up_down && two_up <= down_up)
		return (two_up);
	if (two_down <= two_up && two_down <= up_down && two_down <= down_up)
		return (two_down);
	if (up_down <= two_up && up_down <= two_down && up_down <= down_up)
		return (up_down);
	if (down_up <= two_up && down_up <= two_down && down_up <= up_down)
		return (down_up);
}

void	min_operations(t_stacks *stacks)
{
	int	i;
	int	j;
	int	jj;

	i = 0;
	while (i <= stacks->size_a)
	{
		j = 0;
		while (j <= stacks->size_b)
		{
			jj = j + 1;
			if (jj == stacks->size_b)
				jj = 0;
			if (stacks->a[i] < stacks->b[j] and stacks->a[i] < stacks->b[jj])
				stacks->min_operations[i] = min_operation(i, j, stacks);
			j++;
		}
		i++;
	}
}
