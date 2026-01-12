/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shfujita <shfujita@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 13:34:53 by shfujita          #+#    #+#             */
/*   Updated: 2025/05/07 17:56:10 by shfujita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size_itoa(long num)
{
	int	size;

	size = 0;
	if (num < 0)
		size++;
	if (num == 0)
		size++;
	while (num)
	{
		size++;
		num /= 10;
	}
	return (size);
}

char	*set_itoa(char *res, long num, int size)
{
	res[size] = '\0';
	if (num < 0)
	{
		res[0] = '-';
		num = -num;
	}
	if (num == 0)
		res[0] = '0';
	while (num)
	{
		res[--size] = num % 10 + '0';
		num /= 10;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	long	num;
	int		size;

	num = (long)n;
	size = size_itoa(num);
	res = malloc(size + 1);
	if (!res)
		return (NULL);
	return (set_itoa(res, num, size));
}
