/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzridi <mzridi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 22:12:58 by mzridi            #+#    #+#             */
/*   Updated: 2022/08/15 21:18:56 by mzridi           ###   ########.fr       */
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
	stacks->operations = ft_strjoin(tmp, s);
	free(tmp);
	if (!stacks->operations)
		return ;
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

	op = ft_split(stacks->operations, ' ');
	ra = 0;
	rb = 0;
	while (*op)
	{
		while (*op && (*op)[0] != 'p')
		{
			if ((*op)[0] == 'r' && (*op)[1] == 'a')
				ra += 1;
			else if ((*op)[0] == 'r' && (*op)[1] == 'b')
				rb += 1;
			else if ((*op)[0] == 'r' && (*op)[1] == 'r' && (*op)[2] == 'a')
				ra -= 1;
			else if ((*op)[0] == 'r' && (*op)[1] == 'r' && (*op)[2] == 'b')
				rb -= 1;
			op++;
		}
		print(ra, rb);
		ra = 0;
		rb = 0;
		if (*op)
		{
			printf("%s\n", *op);
			op++;
		}
	}
}
