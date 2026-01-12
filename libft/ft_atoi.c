/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shfujita <shfujita@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:38:16 by shfujita          #+#    #+#             */
/*   Updated: 2025/05/09 20:45:41 by shfujita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_atoi(const char *s)
{
	int			sign;
	long long	res;

	res = 0;
	sign = 1;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s && (*s >= '0' && *s <= '9'))
	{
		res = res * 10 + *s - '0';
		s++;
	}
	res *= sign;
	return ((int)res);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d\n", atoi("2147483649"));
// 	printf("%d\n", ft_atoi("2147483649"));
// 	printf("%d\n", atoi("-2147483649"));
// 	printf("%d\n", ft_atoi("-2147483649"));
// 	printf("%d\n", atoi("-99999999999999999999999999999999999999"));
// 	printf("%d\n", ft_atoi("-99999999999999999999999999999999999999"));
// 	printf("%d\n", atoi("    ---123"));
// 	printf("%d\n", ft_atoi("    ---123"));
// 	printf("%d\n", atoi("-123aaaaa"));
// 	printf("%d\n", ft_atoi("-123aaaaa"));
// 	return (0);
// }
