/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzridi <mzridi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 16:39:40 by mzridi            #+#    #+#             */
/*   Updated: 2022/06/26 17:55:17 by mzridi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sa(int **arr, int size)
{
	int	tmp;

	tmp = arr[size - 1];
	*arr[size - 1] = arr[size - 2];
	*arr[size - 2] = tmp;
}

void	ss(int *a, int *b, int size)
{
	sa(a, size);
	sa(b, size);
}

void	pa(int **a, int *size_a, int **b, int *size_b)
{
	int	tmp;

	*a[*size_a - 1] = *b[*size_b - 1];
	*size_a += 1;
	*size_b -= 1;
}

void	pb(int **a, int *size_a, int **b, int *size_b)
{
	pa(b, size_b, a, size_a);
}

void	ra(int **arr, int size)
{
	int	tmp;

	tmp = *arr[size - 1];
	while (size > 1)
	{
		*arr[size - 1] = *arr[size - 2];
		size -= 1;
	}
	*arr[0] = tmp;
}
