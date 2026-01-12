/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shfujita <shfujita@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:47:33 by shfujita          #+#    #+#             */
/*   Updated: 2025/05/01 15:54:17 by shfujita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		len;
	int		i;

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

// #include <stdio.h>

// int	main(void)
// {
// 	char	*c;

// 	c = ft_strdup("hello");
// 	while (*c)
// 	{
// 		printf("%c", *c);
// 		c++;
// 	}
// 	printf("\n");
// 	return (0);
// }
