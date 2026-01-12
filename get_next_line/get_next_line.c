/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shfujita <shfujita@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:46:50 by shfujita          #+#    #+#             */
/*   Updated: 2026/01/12 15:58:01 by shfujita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(char *stash)
{
	size_t	i;
	char	*res;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	res = ft_substr(stash, 0, i);
	return (res);
}

char	*get_remain_line(char *stash)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = stash;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	tmp = ft_substr(stash, i, ft_strlen(stash + i));
	free(stash);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*buf;
	ssize_t		bytes;

	bytes = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (!ft_strchr(stash, '\n') && bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
			return (free(buf), free(stash), stash = NULL, NULL);
		buf[bytes] = '\0';
		stash = ft_strjoin(stash, buf);
		if (!stash)
			return (free(buf), free(stash), stash = NULL, NULL);
	}
	free(buf);
	line = get_line(stash);
	stash = get_remain_line(stash);
	return (line);
}
