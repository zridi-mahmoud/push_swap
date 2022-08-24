/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzridi <mzridi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:20:15 by mzridi            #+#    #+#             */
/*   Updated: 2022/08/24 22:56:41 by mzridi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stacks
{
	int		size_a;
	int		size_b;
	int		*a;
	int		*b;
	int		size_seq;
	int		*sorted_a;
	int		target_a;
	int		target_b;
	int		error;
	int		max_a;
	int		min_a;
	char	*operations;
	int		rotations;
	int		*v_a;
}				t_stacks;

char	**ft_split(char const *s, char c);
char	*join_args(char **args, int i);
size_t	ft_strlen(const char *s);
long	ft_atoi(const char *str);
int		*lis(t_stacks *stacks, int *dp);
void	sa(t_stacks *stacks, int type, int print);
void	ss(t_stacks *stacks, int print);
void	pa(t_stacks *stacks);
void	pb(t_stacks *stacks);
void	ra(t_stacks *stacks, int type, int print);
void	rr(t_stacks *stacks, int print);
void	rra(t_stacks *stacks, int type, int print);
void	rrr(t_stacks *stacks, int print);
int		init_stacks(t_stacks *stacks, int size, int *int_tab);
void	get_min_operation(t_stacks *stacks);
void	r_up_up(t_stacks *stacks);
void	r_down_down(t_stacks *stacks);
void	r_up_down(t_stacks *stacks);
void	r_down_up(t_stacks *stacks);
int		push_it_to_a(t_stacks *stacks);
int		push_lis(t_stacks *stacks);
char	*ft_strjoin(char const *s1, char const *s2);
void	save_op(t_stacks *stacks, char *s);
void	compress(int ra, int rb, char **op);
int		max(int a, int b);
void	debug_tab(int *a, int size);
void	free_tab(char **t);
void	free_stack(t_stacks *stacks);
int		sorted(t_stacks *stacks);
void	get_min_max(t_stacks *stacks);
void	rotate_a(t_stacks *stacks);
int		ft_tab_len(char **tab);
int		tab_int_len(int *tab);
void	swap_i_j(t_stacks *stacks, int i, int j);
char	*get_next_line(int fd);
int		ft_strchr(const char *s, int c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*return_line_helper(char **st_line, char *copy, char *line);
char	*ft_next_line_helper(int int_var, char **line, char *copy, int fd);
int		*ft_str_to_int(char **str_tab);
int		get_inp(char **argv, int **int_inp);
int		len(char *s);
void	ft_putstr(char *s);

#endif