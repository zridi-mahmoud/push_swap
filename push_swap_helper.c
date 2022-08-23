/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzridi <mzridi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 19:28:08 by mzridi            #+#    #+#             */
/*   Updated: 2022/08/23 19:35:55 by mzridi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			printf("Error\n");
			free(int_tab);
			return (0);
		}
		int_tab[i] = tmp;
		i++;
	}
	return (int_tab);
}
