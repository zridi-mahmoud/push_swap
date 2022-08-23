/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzridi <mzridi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 19:21:20 by mzridi            #+#    #+#             */
/*   Updated: 2022/08/23 20:54:58 by mzridi           ###   ########.fr       */
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
	else 
		return (0);
	return (1);
}

int	is_sorted(t_stacks *s)
{
	int	i;

	i = 0;
	if (s->size_b != 0)
		return(0);
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

	// fd = fileno(fopen("./instructions", "r"));
	fd = 0;
	op = NULL;
	op = get_next_line(fd);
	while(op)
	{
		if (!execute_op(op, stacks))
		{
			if(op)
				free(op);
			printf("Error\n");
		}
		if (op)	
			free(op);
		// printf("%s\n",op);
		op = get_next_line(fd);
	}
	if (is_sorted(stacks))
		printf("OK\n");
	else
		printf("KO\n");
}

int	main(int argc, char **argv)
{
	char		**str_tab;
	int			*int_tab;
	char		*str;
	t_stacks	*stacks;

	if (argc == 1)
		return (0);
	str = join_args(argv, 1);
	if (!str)
		return (0);
	str_tab = ft_split(str, ' ');
	free(str);
	int_tab = ft_str_to_int(str_tab);
	if (!int_tab)
		return (1);
	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (!stacks)
		return (0);
	if (!init_stacks(stacks, ft_tab_len(str_tab), int_tab))
	{
		printf("Error\n");
		return (1);
	}
	check(stacks);
	free_stack(stacks, str_tab);
	return (0);
}
