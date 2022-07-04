/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzridi <mzridi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:20:15 by mzridi            #+#    #+#             */
/*   Updated: 2022/07/04 21:58:26 by mzridi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stacks
{
	int	size_a;
	int	size_b;
	int	*a;
	int	*b;
	int	size_seq;
	int	*sorted_a;
	int	*min_operations;
	int	index_min_operation;
}				t_stacks;

char	**ft_split(char const *s, char c);
char	*join_args(char **args);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
int		*lis(t_stacks *stacks, int *dp);
void	sa(t_stacks *stacks, int type, int print);
void	ss(t_stacks *stacks);
void	pa(t_stacks *stacks, int type);
void	ra(t_stacks *stacks, int type, int print);
void	rr(t_stacks *stacks);
void	rra(t_stacks *stacks, int type, int print);
void	rrr(t_stacks *stacks);
int		init_stacks(t_stacks *stacks, int size, int *int_tab);

#endif