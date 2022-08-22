/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzridi <mzridi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:49:46 by mzridi            #+#    #+#             */
/*   Updated: 2022/08/23 00:17:56 by mzridi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	get_pos(char *str)
{
	int		i;
	long	result;

	i = 0;
	result = 0;
	while (str[i])
	{
		if (str[i] <= '9' && str[i] >= '0')
		{
			result *= 10;
			result += str[i] - 48;
			i++;
		}
		else
			return (21474836490);
	}
	return (result);
}

long	ft_atoi(const char *str)
{
	int		i;
	long	result;
	char	*strcp;

	i = 0;
	strcp = (char *) str;
	result = 1;
	if (strcp[i] == '-' || strcp[i] == '+')
	{
		if (strcp[i] == '-')
			result *= -1;
		i++;
	}
	result *= get_pos(strcp + i);
	return (result);
}
