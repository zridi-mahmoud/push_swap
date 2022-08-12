/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzridi <mzridi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 18:16:11 by mzridi            #+#    #+#             */
/*   Updated: 2022/08/12 15:56:29 by mzridi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	r_up_up(t_stacks *stacks)
{
	int	i;
	int	j;

	i = stacks->target_a;
	j = stacks->target_b;
	while (i-- > 0)
		ra(stacks, 0, 1);
	while (j-- > 0)
		ra(stacks, 1, 1);
}

void	r_down_down(t_stacks *stacks)
{
	int	i;
	int	j;

	i = stacks->target_a;
	j = stacks->target_b;
	while (i-- > 0)
		rra(stacks, 0, 1);
	while (j-- > 0)
		rra(stacks, 1, 1);
}

void	r_up_down(t_stacks *stacks)
{
	int	i;
	int	j;

	i = stacks->target_a;
	j = stacks->target_b;
	while (i-- > 0)
		ra(stacks, 0, 1);
	while (j-- > 0)
		rra(stacks, 1, 1);
}

void	r_down_up(t_stacks *stacks)
{
	int	i;
	int	j;

	i = stacks->target_a;
	j = stacks->target_b;
	while (i-- > 0)
		rra(stacks, 0, 1);
	while (j-- > 0)
		ra(stacks, 1, 1);
}
