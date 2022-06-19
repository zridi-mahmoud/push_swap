/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzridi <mzridi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 13:35:34 by mzridi            #+#    #+#             */
/*   Updated: 2022/06/19 14:24:07 by mzridi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

size_t	ft_strlen(const char *s)
{
	unsigned int	count;

	count = 0;
	while (s[count])
		count ++;
	return (count);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			size_s1;
	size_t			size_s2;
	char			*result;
	unsigned int	i;

	if (!s1 || !s2)
		return (NULL);
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	result = malloc(size_s1 + size_s2 + 1);
	if (!result)
		return (NULL);
	result[size_s1 + size_s2] = 0;
	i = 0;
	while (*s1)
		result[i++] = *s1++;
	while (*s2)
		result[i++] = *s2++;
	return (result);
}

char	*join_args(char **args)
{
	char	*tmp;
	char	*tmp2;
	char	*result;
	int		i;

	result = malloc(sizeof(char));
	if (!result)
		return (NULL);
	i = 1;
	while (args[i])
	{
		tmp = result;
		tmp2 = ft_strjoin(result, " ");
		result = ft_strjoin(tmp2, args[i]);
		free(tmp);
		free(tmp2);
		if (!result)
			return (NULL);
		i++;
	}
	return (result);
}
