/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzridi <mzridi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:23:46 by mzridi            #+#    #+#             */
/*   Updated: 2022/08/23 00:17:41 by mzridi           ###   ########.fr       */
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

int	push_swap(t_stacks *stacks)
{
	if (!push_lis(stacks))
	{
		printf("Error\n");
		return (0);
	}
	debug_tab(stacks->a, stacks->size_a);
	get_min_max(stacks);
	while (stacks->size_b > 0)
	{
		// printf("max: %d, min: %d\n", stacks->max_a, stacks->min_a);
		get_min_operation(stacks);
		if (!push_it_to_a(stacks))
			break ;
	}
	rotate_a(stacks);
	return (1);
}

// (void)argc;
// (void)argv;
// char	*test[] = {"", "1 3 2 5 0 -1", NULL};
// str = join_args(test);
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
	int_tab = ft_str_to_int(str_tab);
	free(str);
	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (!stacks)
		return (0);
	if (!init_stacks(stacks, ft_tab_len(str_tab), int_tab))
	{
		printf("Error\n");
		return (1);
	}
	if (push_swap(stacks))
		compress(0, 0, ft_split(stacks->operations, ' '));
	free_stack(stacks, str_tab);
	return (0);
}
