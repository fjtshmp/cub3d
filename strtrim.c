#include "cub3d.h"

static int	is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static size_t	ft_strlen(const char *s)
{
	size_t	i = 0;

	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

static char	*ft_substr(const char *s, size_t start, size_t len)
{
	size_t	i;
	char	*out;

	out = (char *)malloc(len + 1);
	if (!out)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		out[i] = s[start + i];
		i++;
	}
	out[i] = '\0';
	return (out);
}

char	*strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && is_in_set(s1[end - 1], set))
		end--;
	return (ft_substr(s1, start, end - start));
}