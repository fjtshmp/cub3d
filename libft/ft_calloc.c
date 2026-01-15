/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shfujita <shfujita@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:41:52 by shfujita          #+#    #+#             */
/*   Updated: 2025/05/08 14:41:35 by shfujita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	max;
	size_t	total;

	max = (size_t)-1;
	if (size != 0 && max / size < nmemb)
		return (NULL);
	total = nmemb * size;
	if (total == 0)
		total = 1;
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total);
	return (ptr);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	*tes;
// 	int	*testes;

// 	tes = ft_calloc(5, sizeof(int));
// 	for (int i = 0; i < 5; i++)
// 	{
// 		printf("%d\n", *tes);
// 		tes++;
// 	}
// 	tes = calloc((size_t)-1, sizeof(char));
// 	if (tes == NULL)
// 		printf("fail\n");
// 	return (0);
// }
