/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzridi <mzridi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 20:07:59 by mzridi            #+#    #+#             */
/*   Updated: 2022/08/22 23:34:32 by mzridi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	free_tab(char **t)
{
	char	**ref;

	ref = t;
	while (*t)
	{
		free(*t);
		t++;
	}
	free(ref);
}

void	free_stack(t_stacks *stacks, char **str_tab)
{
	free_tab(str_tab);
	free(stacks->a);
	free(stacks->b);
	free(stacks->sorted_a);
	// free(stacks->v_a);
}
