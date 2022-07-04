/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzridi <mzridi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:23:46 by mzridi            #+#    #+#             */
/*   Updated: 2022/07/04 21:34:40 by mzridi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	i = 0;
	n = ft_tab_len(str_tab);
	int_tab = (int *)malloc(sizeof(int *) * (n + 1));
	if (!int_tab)
		return (NULL);
	while (str_tab[i])
	{
		int_tab[i] = ft_atoi(str_tab[i]);
		i++;
	}
	return (int_tab);
}

void	push_swap(t_stacks *stacks)
{
	int	min_cost;
	int	index;
	int	i;

	push_lis(stacks);
	while (stacks->size_a > 0)
	{
		
	}
}

int	main(int argc, char **argv)
{
	char		**str_tab;
	int			*int_tab;
	char		*str;
	t_stacks	*stacks;

	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (argc == 1)
		return (0);
	str = join_args(argv);
	if (!str)
		return (0);
	str_tab = ft_split(str, ' ');
	int_tab = ft_str_to_int(str_tab);
	free(str);
	if (!init_stacks(stacks, ft_tab_len(str_tab), int_tab))
		return (0);
	push_swap(stacks);
	while (stacks->size_a--)
		free(str_tab[stacks->size_a]);
	free(stacks->a);
	free(stacks->b);
	free(stacks->sorted_a);
	free(stacks);
	return (0);
}
