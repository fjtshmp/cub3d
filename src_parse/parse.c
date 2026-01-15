/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shfujita <shfujita@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:22:04 by shfujita          #+#    #+#             */
/*   Updated: 2026/01/15 20:06:58 by shfujita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_parse(t_parse *parse)
{
	int	i;

	parse->state = ST_CFG;
	i = 0;
	while (i < 4)
		parse->tex_set[i++] = 0;
	parse->f_set = 0;
	parse->c_set = 0;
	parse->lines = NULL;
	parse->line_count = 0;
	parse->cap = 0;
	parse->max_width = 0;
	parse->player_count = 0;
	parse->fd = -1;
	parse->cur_line = NULL;
	parse->cur_trim = NULL;
}

void	cleanup_state(t_game *state)
{
	if (!state)
		return ;
	free_tex_paths(state);
	free_map_grid(state);
}

void	parse_fatal(t_game *state, t_parse *parse, const char *msg)
{
	drain_gnl_and_close(parse);
	free_parse(parse);
	cleanup_state(state);
	if (msg)
	{
		write(2, "Error\n", 6);
		write(2, msg, (int)ft_strlen(msg));
		write(2, "\n", 1);
	}
	exit(1);
}

static void	open_map(t_game *state, t_parse *parse, const char *path, int *fd)
{
	*fd = open(path, O_RDONLY);
	if (*fd < 0)
	{
		perror("open");
		parse_fatal(state, parse, "failed to open .cub");
	}
}

void	parse(t_game *state, const char *path)
{
	t_parse	parse;
	char	*raw;

	init_parse(&parse);
	open_map(state, &parse, path, &parse.fd);
	raw = get_next_line(parse.fd);
	while (raw)
	{
		parse_line(state, &parse, raw);
		raw = get_next_line(parse.fd);
	}
	close(parse.fd);
	finalize_parse(state, &parse);
	free_parse(&parse);
}
