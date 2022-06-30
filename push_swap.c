/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzridi <mzridi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:23:46 by mzridi            #+#    #+#             */
/*   Updated: 2022/06/30 22:46:32 by mzridi           ###   ########.fr       */
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
	int			*dp;
	int			*seq;
	int			i;

	dp = NULL;
	seq = (int *)malloc(sizeof(int) * stacks->size_a);
	seq = lis(stacks->a, stacks->size_a, dp);
	for (i = 0; i < 6; i++)
		printf("%d ", seq[i]);
	printf("\n");
}

int	main(int argc, char **argv)
{
	char		**str_tab;
	int			*int_tab;
	char		*str;
	t_stacks	*stacks;
	int			i;

	if (argc == 1)
		return (0);
	str = join_args(argv);
	str_tab = ft_split(str, ' ');
	int_tab = ft_str_to_int(str_tab);
	free(str);
	free(str_tab);
	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	stacks->a = int_tab;
	stacks->b = NULL;
	stacks->size_a = ft_tab_len(str_tab);
	// push_swap(stacks);
	for (i = 0; i < stacks->size_a; i++)
		printf("%d ", int_tab[i]);
	printf("\n");
	return (0);
}
