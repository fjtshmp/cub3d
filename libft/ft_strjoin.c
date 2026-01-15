/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shfujita <shfujita@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:00:44 by shfujita          #+#    #+#             */
/*   Updated: 2025/05/03 17:59:58 by shfujita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = malloc(len1 + len2 + 1);
	if (!res)
		return (NULL);
	ft_memcpy(res, s1, len1);
	ft_memcpy(res + len1, s2, len2 + 1);
	return (res);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	c[] = "hello,";
// 	char	cc[] = "world";
// 	char	*tes;

// 	tes = ft_strjoin(c, cc);
// 	while (*tes)
// 	{
// 		printf("%c", *tes);
// 		tes++;
// 	}
// 	printf("\n");
// 	return (0);
// }
