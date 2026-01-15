/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shfujita <shfujita@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 14:34:50 by shfujita          #+#    #+#             */
/*   Updated: 2025/05/01 22:01:46 by shfujita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d < s)
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else if (d > s)
	{
		i = n;
		while (i > 0)
		{
			d[i - 1] = s[i - 1];
			i--;
		}
	}
	return (dest);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	a[7] = {1, 2, 3, 4, 5, 6, 7};

// 	ft_memmove(a + 2, a, sizeof(int) * 5);
// 	for (int i = 0; i < 7; i++)
// 	{
// 		printf("%d\n", a[i]);
// 	}
// }
