/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzridi <mzridi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:23:46 by mzridi            #+#    #+#             */
/*   Updated: 2022/08/14 22:18:33 by mzridi           ###   ########.fr       */
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

void	push_swap(t_stacks *stacks)
{
	push_lis(stacks);
	while (stacks->size_a > 0)
	{
		get_min_operation(stacks);
		if (!push_it_to_b(stacks))
			break ;
	}
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
	debug_tab(int_tab, ft_tab_len(str_tab));
	push_swap(stacks);
	debug_tab(stacks->a, stacks->size_a);
	debug_tab(stacks->b, stacks->size_b);
	while (stacks->size_a--)
		free(str_tab[stacks->size_a]);
	free(stacks->a);
	free(stacks->b);
	free(stacks->sorted_a);
	free(stacks);
	return (0);
}
