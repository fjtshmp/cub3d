/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yseto < yseto@student.42tokyo.jp Mail>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 18:33:58 by yseto             #+#    #+#             */
/*   Updated: 2026/01/06 18:36:14 by yseto            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static size_t	str_len(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

void	print_error(char *msg)
{
	write(2, "Error\n", 6);
	if (msg)
	{
		write(2, msg, str_len(msg));
		write(2, "\n", 1);
	}
	exit(EXIT_FAILURE);
}
