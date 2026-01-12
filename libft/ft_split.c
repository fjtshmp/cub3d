/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shfujita <shfujita@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:14:45 by shfujita          #+#    #+#             */
/*   Updated: 2025/05/09 16:19:14 by shfujita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	cnt;

	cnt = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			cnt++;
			while (*s && *s != c)
				s++;
		}
	}
	return (cnt);
}

static char	*alloc_words(const char *start, char c)
{
	size_t	len;
	char	*word;

	len = 0;
	while (start[len] && start[len] != c)
		len++;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	ft_strlcpy(word, start, len + 1);
	return (word);
}

static void	*free_all(char **res, int id)
{
	while (id--)
		free(res[id]);
	free(res);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	char	*word;
	int		id;

	id = 0;
	res = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!res)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			word = alloc_words(s, c);
			if (!word)
				return (free_all(res, id));
			res[id++] = word;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	res[id] = NULL;
	return (res);
}
