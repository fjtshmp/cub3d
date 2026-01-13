/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shfujita <shfujita@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 14:55:44 by shfujita          #+#    #+#             */
/*   Updated: 2026/01/13 14:58:04 by shfujita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*gnl_strchr(const char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (c == 0)
		return ((char *)str);
	return (NULL);
}

char	*gnl_strdup(const char *s)
{
	char	*dup;
	int		len;
	int		i;

	if (!s)
		return (NULL);
	len = 0;
	while (s[len])
		len++;
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len + 1)
	{
		dup[i] = s[i];
		i++;
	}
	return (dup);
}

char	*gnl_substr(const char *s, unsigned int start, size_t len)
{
	size_t	sublen;
	size_t	i;
	char	*res;

	if (!s)
		return (NULL);
	if (start >= gnl_strlen(s))
		return (NULL);
	i = start;
	while (s[i] && len--)
		i++;
	sublen = i - start;
	res = malloc(sizeof(char) * sublen + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < sublen)
	{
		res[i] = s[i + start];
		i++;
	}
	res[sublen] = '\0';
	return (res);
}

char	*gnl_strjoin(char *dest, char const *src)
{
	size_t	len1;
	size_t	len2;
	char	*res;
	size_t	i;

	if (!dest)
		dest = gnl_strdup("");
	len1 = gnl_strlen(dest);
	len2 = gnl_strlen(src);
	res = malloc(len1 + len2 + 1);
	if (!res || !dest)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		res[i] = dest[i];
		i++;
	}
	while (i < len1 + len2)
	{
		res[i] = src[i - len1];
		i++;
	}
	free(dest);
	return (res[i] = '\0', res);
}
