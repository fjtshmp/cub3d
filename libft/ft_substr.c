/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shfujita <shfujita@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:05:39 by shfujita          #+#    #+#             */
/*   Updated: 2025/05/03 17:28:45 by shfujita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	sublen;
	size_t	i;
	char	*res;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	i = start;
	while (s[i] && len--)
		i++;
	sublen = i - start;
	res = malloc(sizeof(char) * sublen + 1);
	if (!res)
		return (NULL);
	ft_memcpy(res, s + start, sublen);
	res[sublen] = '\0';
	return (res);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	c[] = "hello,world";
// 	char	*cpy;

// 	cpy = ft_substr(c, 6, 10);
// 	while (*cpy)
// 	{
// 		printf("%c", *cpy);
// 		cpy++;
// 	}
// 	printf("\n");
// 	return (0);
// }
