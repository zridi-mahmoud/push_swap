/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzridi <mzridi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:23:46 by mzridi            #+#    #+#             */
/*   Updated: 2022/08/18 21:03:15 by mzridi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	debug_tab(int *a, int size)
{
	int	i;

	i = 0;
	while (i < size)
		printf("%d ", a[i++]);
	printf ("\n");
}

int	ft_tab_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	tab_int_len(int *tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	*ft_str_to_int(char **str_tab)
{
	int		i;
	int		n;
	int		*int_tab;
	long	tmp;

	i = 0;
	n = ft_tab_len(str_tab);
	int_tab = (int *)malloc(sizeof(int *) * (n + 1));
	if (!int_tab)
		return (0);
	while (str_tab[i])
	{
		tmp = ft_atoi(str_tab[i]);
		if (tmp > 2147483647 || tmp < -2147483648)
		{
			printf("Only integers are allowed\n");
			free(int_tab);
			return (0);
		}
		int_tab[i] = tmp;
		i++;
	}
	return (int_tab);
}

void	get_min_max(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->size_a)
	{
		if (stacks->a[i] > stacks->max_a)
			stacks->max_a = stacks->a[i];
		if (stacks->a[i] < stacks->min_a)
			stacks->min_a = stacks->a[i];
		i++;
	}
}

void	rotate_a(t_stacks *stacks)
{
	int	i;

	i = -1;
	while (++i < stacks->size_a)
		if (stacks->a[i] == stacks->min_a)
			break ;
	if (i < stacks->size_a / 2)
		while (i--)
			ra(stacks, 1, 1);
	else
		while (i++ < stacks->size_a)
			rra(stacks, 1, 1);
}

void	push_swap(t_stacks *stacks)
{
	push_lis(stacks);
	get_min_max(stacks);
	while (stacks->size_b > 0)
	{
		get_min_operation(stacks);
		if (!push_it_to_a(stacks))
			break ;
	}
	rotate_a(stacks);
}

int	main(int argc, char **argv)
{
	char		**str_tab;
	int			*int_tab;
	char		*str;
	t_stacks	*stacks;

	if (argc == 1)
		return (0);
	str = join_args(argv);
	// (void)argc;
	// (void)argv;
	// char	*test[] = {"", "1 3 2 5 0 -1", NULL};
	// str = join_args(test);
	if (!str)
		return (0);
	str_tab = ft_split(str, ' ');
	int_tab = ft_str_to_int(str_tab);
	free(str);
	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (!stacks)
		return (0);
	if (!init_stacks(stacks, ft_tab_len(str_tab), int_tab))
		return (0);
	push_swap(stacks);
	compress(stacks);
	debug_tab(stacks->a, stacks->size_a);
	while (stacks->size_a--)
		free(str_tab[stacks->size_a]);
	free(stacks->a);
	free(stacks->b);
	free(stacks->sorted_a);
	free(stacks);
	return (0);
}
