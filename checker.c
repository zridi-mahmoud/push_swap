/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzridi <mzridi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 19:21:20 by mzridi            #+#    #+#             */
/*   Updated: 2022/08/24 23:07:31 by mzridi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap_bonus.h"
#include<stdio.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*sc1;
	unsigned char	*sc2;
	unsigned int	i;

	sc1 = (unsigned char *)s1;
	sc2 = (unsigned char *)s2;
	i = 0;
	while (*sc1 || *sc2)
	{
		if (*sc1 == *sc2)
		{
			i++;
			sc1++;
			sc2++;
			continue ;
		}
		else
		{
			return (*sc1 - *sc2);
		}
	}
	return (0);
}

int	execute_op(char *op, t_stacks	*stacks)
{
	if (!ft_strcmp(op, "ra\n"))
		ra(stacks, 1, 0);
	else if (!ft_strcmp(op, "rb\n"))
		ra(stacks, 0, 0);
	else if (!ft_strcmp(op, "rra\n"))
		rra(stacks, 1, 0);
	else if (!ft_strcmp(op, "rrb\n"))
		rra(stacks, 0, 0);
	else if (!ft_strcmp(op, "pa\n"))
		pa(stacks);
	else if (!ft_strcmp(op, "pb\n"))
		pb(stacks);
	else if (!ft_strcmp(op, "rr\n"))
		rr(stacks, 0);
	else if (!ft_strcmp(op, "rrr\n"))
		rrr(stacks, 0);
	else if (!ft_strcmp(op, "sa\n"))
		sa(stacks, 1, 0);
	else if (!ft_strcmp(op, "sb\n"))
		sa(stacks, 0, 0);
	else if (!ft_strcmp(op, "ss\n"))
		ss(stacks, 0);
	else
		return (0);
	return (1);
}

int	is_sorted(t_stacks *s)
{
	int	i;

	i = 0;
	if (s->size_b != 0)
		return (0);
	while (i < s->size_a)
	{
		if (s->sorted_a[i] != s->a[i])
			return (0);
		i++;
	}
	return (1);
}

void	check(t_stacks *stacks)
{
	char	*op;
	int		fd;

	fd = 0;
	op = NULL;
	op = get_next_line(fd);
	while (op)
	{
		if (!execute_op(op, stacks))
		{
			op = NULL;
			free(op);
			return (printf("Error\n"), 0);
		}
		if (op)
			free(op);
		op = get_next_line(fd);
	}
	if (is_sorted(stacks))
		printf("OK\n");
	else
		printf("KO\n");
}

int	main(int argc, char **argv)
{
	int			len;
	int			*int_tab;
	t_stacks	*stacks;

	if (argc == 1)
		return (0);
	int_tab = 0;
	len = get_inp(argv, &int_tab);
	if (!len)
		return (printf("Error\n"), 1);
	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (!stacks)
		return (printf("Error\n"), 1);
	if (!init_stacks(stacks, len, int_tab))
		return (printf("Error\n"), 1);
	check(stacks);
	free_stack(stacks);
	return (0);
}
