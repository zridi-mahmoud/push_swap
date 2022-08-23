/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzridi <mzridi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:29:10 by mzridi            #+#    #+#             */
/*   Updated: 2022/08/23 19:19:10 by mzridi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap_bonus.h"

int	ft_strchr(const char *s, int c)
{
	unsigned int	i;
	unsigned char	*sc;

	sc = (unsigned char *)s;
	i = 0;
	while (sc[i])
	{
		if (sc[i] == (unsigned char)c)
			return (i);
		i++;
	}
	return (-1);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*result;

	result = malloc(count * size);
	if (!result)
		return (NULL);
	size = size * count;
	while (size-- > 0)
		result[size] = 0;
	return (result);
}

char	*ft_strdup(const char *s1)
{
	unsigned int	size;
	char			*result;
	unsigned int	i;
	char			*scp;

	scp = (char *)s1;
	i = 0;
	size = ft_strlen(s1);
	result = ft_calloc(size + 1, 1);
	if (!result)
		return (NULL);
	while (i < size)
	{
		result[i] = scp[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

char	*return_line_helper(char **st_line, char *copy, char *line)
{
	free(*st_line);
	*st_line = ft_strdup(copy);
	free(copy);
	if (!*st_line)
	{
		free(line);
		free(*st_line);
		return (NULL);
	}
	return (line);
}

char	*ft_next_line_helper(int int_var, char **line, char *copy, int fd)
{
	char		*tmp;

	if (!int_var)
	{
		free(copy);
		if (*line[fd] != '\0')
		{
			copy = ft_strdup(line[fd]);
			free(line[fd]);
			line[fd] = NULL;
			return (copy);
		}
		else
		{
			free(line[fd]);
			return (line[fd] = NULL);
		}
	}
	tmp = line[fd];
	line[fd] = ft_strjoin(line[fd], copy);
	free(tmp);
	free(copy);
	if (!line[fd])
		return (NULL);
	return (get_next_line(fd));
}
