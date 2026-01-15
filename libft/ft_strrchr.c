/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shfujita <shfujita@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:48:34 by shfujita          #+#    #+#             */
/*   Updated: 2025/05/01 22:06:17 by shfujita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	char			*out;
	unsigned char	find;

	find = (unsigned char)c;
	out = 0;
	while (*str)
	{
		if (*str == find)
			out = (char *)str;
		str++;
	}
	if (!*str && find == '\0')
		return ((char *)str);
	return (out);
}
