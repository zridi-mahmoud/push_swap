/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzridi <mzridi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:23:46 by mzridi            #+#    #+#             */
/*   Updated: 2022/06/19 15:50:11 by mzridi           ###   ########.fr       */
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

int	**ft_str_to_int(char **str_tab)
{
	int		i;
	int		n;
	int		**int_tab;

	i = 0;
	n = ft_tab_len(str_tab);
	int_tab = (int **)malloc(sizeof(int *) * (n + 1));
	if (!int_tab)
		return (NULL);
	while (str_tab[i])
	{
		int_tab[i] = (int *)malloc(sizeof(int *));
		if (!int_tab[i])
		{
			while (--i >= 0)
				free(int_tab[i]);
			free(int_tab);
			return (NULL);
		}
		*int_tab[i] = ft_atoi(str_tab[i]);
		i++;
	}
	return (int_tab);
}

int	main(int argc, char **argv)
{
	char	**str_tab;
	int		**int_tab;
	char	*str;
	int		i;

	if (argc == 1)
		return (0);
	str = join_args(argv);
	str_tab = ft_split(str, ' ');
	int_tab = ft_str_to_int(str_tab);
	free(str);
	free(str_tab);
	i = 0;
	while (int_tab[i])
	{
		printf("%d\n", *int_tab[i]);
		i++;
	}
	return (0);
}
