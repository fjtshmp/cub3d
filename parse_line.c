/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shfujita <shfujita@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:01:23 by shfujita          #+#    #+#             */
/*   Updated: 2026/01/12 16:52:01 by shfujita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*handle_raw_line(t_game *state, t_parse *parse, char *raw_line)
{
	char	*line;

	line = dup_strip_eol(raw_line);
	free(raw_line);
	if (!line)
		parse_fatal(state, parse, "malloc");
	if (is_blank(line))
	{
		if (parse->state == ST_CFG)
		{
			free(line);
			return (NULL);
		}
		else
		{
			free(line);
			parse_fatal(state, parse, "blank line in map");
		}
	}
	return (line);
}

static void	handle_cfg_line(t_game *state, t_parse *parse, char *line,
		char *trim)
{
	if (is_config_line(trim))
	{
		parse_config_line(state, parse, trim);
		return ;
	}
	if (is_map_line(line))
	{
		parse->state = ST_MAP;
		map_push(state, parse, line);
		return ;
	}
	parse_fatal(state, parse, "invalid line before map");
}

static void	handle_map_line(t_game *state, t_parse *parse, char *line)
{
	if (!is_map_line(line))
		parse_fatal(state, parse, "invalid map line");
	map_push(state, parse, line);
}

void	parse_line(t_game *state, t_parse *parse, char *raw_line)
{
	char	*line;
	char	*trimed_line;

	line = handle_raw_line(state, parse, raw_line);
	if (!line)
		return ;
	trimed_line = ft_strtrim(line, " \t");
	if (!trimed_line)
	{
		free(line);
		parse_fatal(state, parse, "malloc");
	}
	if (parse->state == ST_CFG)
		handle_cfg_line(state, parse, line, trimed_line);
	else
		handle_map_line(state, parse, line);
	free(trimed_line);
	free(line);
}
