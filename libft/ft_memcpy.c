/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shfujita <shfujita@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:58:27 by shfujita          #+#    #+#             */
/*   Updated: 2025/08/02 15:49:52 by shfujita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d == 0 && s == 0)
		return (NULL);
	while (n--)
	{
		*d = *s;
		d++;
		s++;
	}
	return (dest);
}
//引数の片方がNULLのときはsegvで両方がNULLのときreturn (NULL);
// #include <stdio.h>

// int	main(void)
// {
// 	int	a[5] = {1, 2, 3, 4, 5};
// 	int	c[5] = {1, 1, 1, 1, 1};

// 	ft_memcpy(c, a, sizeof(int)*5);
// 	for (int i = 0; i < 5; i++)
// 	{
// 		printf("%d\n", c[i]);
// 	}
// 	return (0);
// }
