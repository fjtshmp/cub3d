/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shfujita <shfujita@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:52:53 by shfujita          #+#    #+#             */
/*   Updated: 2026/01/13 14:55:54 by shfujita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_color	*select_floor_or_ceiling(t_game *state, t_parse *parse,
		char kind)
{
	if (kind == 'F')
	{
		if (parse->f_set)
			parse_fatal(state, parse, "duplicate floor color (F)");
		parse->f_set = 1;
		return (&state->floor);
	}
	if (kind == 'C')
	{
		if (parse->c_set)
			parse_fatal(state, parse, "duplicate ceiling color (C)");
		parse->c_set = 1;
		return (&state->ceiling);
	}
	parse_fatal(state, parse, "invalid color id");
	return (NULL);
}

static void	check_color_range(t_game *state, t_parse *parse, const char **s,
		int *out)
{
	long	value;
	int		num_digit;

	*s = skip_space(*s);
	num_digit = 0;
	value = 0;
	while (**s && ft_isdigit(**s))
	{
		num_digit = 1;
		value = value * 10 + (**s - '0');
		if (value > 255)
			parse_fatal(state, parse, "color component out of range (0-255)");
		(*s)++;
	}
	if (!num_digit)
		parse_fatal(state, parse, "invalid color format");
	*out = (int)value;
	*s = skip_space(*s);
}

static void	expect_comma(t_game *state, t_parse *parse, const char **s)
{
	if (**s != ',')
		parse_fatal(state, parse, "invalid color format (missing comma)");
	(*s)++;
}

void	parse_color_line(t_game *state, t_parse *parse, const char *trimed_line)
{
	t_color		*dst;
	const char	*s;

	dst = select_floor_or_ceiling(state, parse, trimed_line[0]);
	s = skip_space(trimed_line + 1);
	check_color_range(state, parse, &s, &dst->red);
	expect_comma(state, parse, &s);
	check_color_range(state, parse, &s, &dst->green);
	expect_comma(state, parse, &s);
	check_color_range(state, parse, &s, &dst->blue);
	s = skip_space(s);
	if (*s != '\0')
		parse_fatal(state, parse, "invalid color format (trailing chars)");
	dst->value = (dst->red << 16) | (dst->green << 8) | (dst->blue);
}
