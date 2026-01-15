/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shfujita <shfujita@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:12:13 by shfujita          #+#    #+#             */
/*   Updated: 2026/01/12 18:20:57 by shfujita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_blank(const char *s)
{
	if (!s)
		return (1);
	while (*s)
	{
		if (*s != ' ' && *s != '\t' && *s != '\n' && *s != '\r')
			return (0);
		s++;
	}
	return (1);
}

char	*dup_strip_eol(const char *s)
{
	size_t	len;
	char	*out;
	size_t	i;

	if (!s)
		return (NULL);
	len = 0;
	while (s[len] && s[len] != '\n' && s[len] != '\r')
		len++;
	out = (char *)malloc(len + 1);
	if (!out)
		return (NULL);
	i = 0;
	while (i < len)
	{
		out[i] = s[i];
		i++;
	}
	out[len] = '\0';
	return (out);
}

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

const char	*skip_space(const char *s)
{
	while (*s && is_space(*s))
		s++;
	return (s);
}
