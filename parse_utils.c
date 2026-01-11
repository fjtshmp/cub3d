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