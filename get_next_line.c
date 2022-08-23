/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzridi <mzridi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 19:28:46 by mzridi            #+#    #+#             */
/*   Updated: 2022/08/23 20:43:40 by mzridi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap_bonus.h"

char	*return_line(char **st_line, int idx, int i)
{
	char	*line;
	char	*copy;
	int		j;

	line = ft_calloc(idx + 2, 1);
	if (!line)
		return (NULL);
	copy = ft_calloc(ft_strlen(*st_line) - idx + 1, 1);
	if (!copy)
	{
		free(line);
		free(*st_line);
		return (*st_line = NULL);
	}
	while ((*st_line)[i] && (*st_line)[i] != '\n')
	{
		line[i] = (*st_line)[i];
		i++;
	}
	line[i++] = '\n';
	line[i--] = '\0';
	j = 0;
	while ((*st_line)[++i])
		copy[j++] = (*st_line)[i];
	return (return_line_helper(st_line, copy, line));
}

char	*get_next_line(int fd)
{
	static char	*line[10240];
	int			int_var;
	char		*copy;

	if (fd < 0 || fd >= 10240)
		return (NULL);
	if (!line[fd])
		line[fd] = ft_strdup("");
	if (!line[fd])
		return (NULL);
	int_var = ft_strchr(line[fd], '\n');
	if (int_var != -1)
		return (return_line(&line[fd], int_var, 0));
	else
	{
		copy = ft_calloc(2, 1);
		int_var = read(fd, copy, 1);
		if (int_var == -1)
		{
			free(copy);
			free(line[fd]);
			return (line[fd] = NULL);
		}
		return (ft_next_line_helper(int_var, line, copy, fd));
	}
}
