/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shfujita <shfujita@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:03:05 by shfujita          #+#    #+#             */
/*   Updated: 2025/05/03 14:37:35 by shfujita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	d;

	ptr = (unsigned char *)s;
	d = (unsigned char)c;
	while (n--)
	{
		if (*ptr == d)
			return (ptr);
		ptr++;
	}
	return (0);
}
