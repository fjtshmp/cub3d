#ifndef OPEN_MAX
# define OPEN_MAX 1024
#endif


#include "cub3d.h"

static size_t	gnl_strlen(const char *s)
{
	size_t	i = 0;

	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

static char	*gnl_strchr(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

static char	*gnl_strjoin_free(char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;
	char	*out;

	len1 = gnl_strlen(s1);
	len2 = gnl_strlen(s2);
	out = (char *)malloc(len1 + len2 + 1);
	if (!out)
		return (free(s1), NULL);
	i = 0;
	while (i < len1)
	{
		out[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len2)
	{
		out[i + j] = s2[j];
		j++;
	}
	out[len1 + len2] = '\0';
	free(s1);
	return (out);
}

/*
** stash から 1行取り出して返す（改行があれば改行込み）
** 取り出した残りを stash に残す
*/
static char	*extract_line(char **stash)
{
	char	*nl;
	char	*line;
	char	*rest;
	size_t	line_len;
	size_t	rest_len;
	size_t	i;

	if (!*stash || **stash == '\0')
		return (NULL);
	nl = gnl_strchr(*stash, '\n');
	line_len = (nl != NULL) ? (size_t)(nl - *stash + 1) : gnl_strlen(*stash);
	line = (char *)malloc(line_len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < line_len)
	{
		line[i] = (*stash)[i];
		i++;
	}
	line[i] = '\0';
	if (!nl)
		return (free(*stash), *stash = NULL, line);
	rest_len = gnl_strlen(*stash + line_len);
	rest = (char *)malloc(rest_len + 1);
	if (!rest)
		return (free(line), NULL);
	i = 0;
	while (i < rest_len)
	{
		rest[i] = (*stash)[line_len + i];
		i++;
	}
	rest[i] = '\0';
	free(*stash);
	*stash = rest;
	return (line);
}

static int	read_to_stash(int fd, char **stash)
{
	char	*buf;
	ssize_t	r;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (-1);
	r = 1;
	while (!gnl_strchr(*stash, '\n') && r > 0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r < 0)
			return (free(buf), -1);
		buf[r] = '\0';
		if (r > 0)
		{
			*stash = gnl_strjoin_free(*stash, buf);
			if (!*stash)
				return (free(buf), -1);
		}
	}
	free(buf);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*stash[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (NULL);
	if (read_to_stash(fd, &stash[fd]) < 0)
		return (free(stash[fd]), stash[fd] = NULL, NULL);
	line = extract_line(&stash[fd]);
	return (line);
}