/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzridi <mzridi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 22:12:58 by mzridi            #+#    #+#             */
/*   Updated: 2022/08/14 23:58:39 by mzridi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	comun(int a, int b)
{
	if (a > 0 && b > 0)
	{
		if (a < b)
			return (a);
		else
			return (b);
	}
	else if (a < 0 && b < 0)
	{
		if (a < b)
			return (b);
		else
			return (a);
	}
	return (0);
}

void	save_op(t_stacks *stacks, char *s)
{
	char	*tmp;

	tmp = stacks->operations;
	stacks->operations = ft_strjoin(tmp, " ");
	free(tmp);
	if (!stacks->operations)
		return (0);
	stacks->operations = ft_strjoin(tmp, s);
	if (!stacks->operations)
		return (0);
}

void	printer(int n, char *op)
{
	if (n > 0)
		while (n--)
			printf("%s\n", op);
	else if (n < 0)
		while (n++)
			printf("r%s\n", op);
}

void	print(int ra, int rb)
{
	int	rr;

	rr = comun(ra, rb);
	printer(rr, "rr");
	printer(ra - rr, "ra");
	printer(rb - rr, "rb");
}

void	compress(t_stacks *stacks)
{
	char	**op;
	int		ra;
	int		rb;

	op = ft_split(stacks->operations, " ");
	ra = 0;
	rb = 0;
	while (*op)
	{
		while (*op && *op != "pa" && *op != "pb")
		{
			if (*op == "ra")
				ra += 1;
			else if (*op == "rb")
				rb += 1;
			else if (*op == "rra")
				ra -= 1;
			else if (*op == "rrb")
				rb -= 1;
			op++;
		}
		print(ra, rb);
	}
}
