/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzridi <mzridi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 21:36:02 by mzridi            #+#    #+#             */
/*   Updated: 2022/08/24 22:54:23 by mzridi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	len(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		if (s[i] != ' ')
			return (1);
	return (0);
}

int	get_inp(char **argv, int **int_tab)
{
	char	**str_tab;
	char	*str;
	int		i;

	i = -1;
	while (argv[++i])
		if (!len(argv[i]))
			return (0);
	str = join_args(argv, 1);
	if (!str)
		return (0);
	str_tab = ft_split(str, ' ');
	free(str);
	if (!str_tab)
		return (0);
	i = ft_tab_len(str_tab);
	*int_tab = ft_str_to_int(str_tab);
	free_tab(str_tab);
	if (!*int_tab)
		return (0);
	return (i);
}

void	ft_putchar_fd(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s)
	{
		ft_putchar_fd(*s++);
	}
}
