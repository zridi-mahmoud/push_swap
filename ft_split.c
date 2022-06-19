/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzridi <mzridi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 14:29:18 by mzridi            #+#    #+#             */
/*   Updated: 2022/06/19 14:37:28 by mzridi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	size_count;

	if (dstsize == 0)
		return (ft_strlen(src));
	size_count = 0;
	while (*src != '\0')
	{
		if (size_count < dstsize - 1)
		{
			*dst = *src;
			dst++;
		}
		src++;
		size_count++;
	}
	*dst = 0;
	return (size_count);
}

static unsigned int	ft_skip(char *s, char c, unsigned int i, int type)
{
	if (type == 1)
	{
		if (c == 0)
			return (i);
		while (s[i] == c)
				i++;
		return (i);
	}
	else
	{
		while (s[i] != c && s[i] != 0)
				i++;
		return (i);
	}
}

static unsigned int	ft_wcount(char *s, char c)
{
	unsigned int	i;
	unsigned int	result;

	i = 0;
	result = 0;
	i = ft_skip(s, c, i, 1);
	while (s[i] != 0)
	{
		result += 1;
		i = ft_skip(s, c, i, 0);
		i = ft_skip(s, c, i, 1);
	}
	return (result);
}

static char	**ft_alloc_words(char *s, char c, char **r, unsigned int wc)
{
	unsigned int	i;
	unsigned int	k;
	unsigned int	j;

	r = malloc((wc + 1) * sizeof(char *));
	if (!r)
		return (NULL);
	i = 0;
	k = 0;
	while (i < wc)
	{
		j = ft_skip(s, c, k, 1);
		k = ft_skip(s, c, j, 0);
		r[i] = malloc(k - j + 1);
		ft_strlcpy(r[i], s + j, k - j + 1);
		if (!r[i++])
		{
			while (--i >= 0)
				free(r[i]);
			free(r);
			return (NULL);
		}	
	}		
	r[i] = NULL;
	return (r);
}

char	**ft_split(char const *s, char c)
{
	char			**result;

	if (!s)
		return (NULL);
	result = NULL;
	result = ft_alloc_words((char *)s, c, result, ft_wcount((char *)s, c));
	if (!result)
		return (NULL);
	return (result);
}
