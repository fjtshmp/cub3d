/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shfujita <shfujita@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:21:03 by shfujita          #+#    #+#             */
/*   Updated: 2025/05/09 20:47:22 by shfujita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *s, const char *find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*find)
		return ((char *)s);
	while (s[i])
	{
		j = 0;
		while (i + j < len && find[j] && find[j] == s[i + j])
			j++;
		if (!find[j])
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}
