/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shfujita <shfujita@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:22:04 by shfujita          #+#    #+#             */
/*   Updated: 2026/01/12 18:22:05 by shfujita         ###   ########.fr       */
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
}

static void	parse_cleanup_game_partial(t_game *g)
{
	if (!g)
		return ;
	free_tex_paths(g);
	free_map_grid(g);
}

void	parse_fatal(t_game *g, t_parse *p, const char *msg)
{
	free_parse(p);
	parse_cleanup_game_partial(g);
	if (msg)
	{
		write(2, "Error\n", 6);
		write(2, msg, (int)ft_strlen(msg));
		write(2, "\n", 1);
	}
	exit(1);
}

static void	open_map(t_game *g, t_parse *p, const char *path, int *fd)
{
	*fd = open(path, O_RDONLY);
	if (*fd < 0)
	{
		perror("open");
		parse_fatal(g, p, "failed to open .cub");
	}
}

void	parse(t_game *state, const char *path)
{
	t_parse	parse;
	int		fd;
	char	*raw;

	init_parse(&parse);
	open_map(state, &parse, path, &fd);
	raw = get_next_line(fd);
	while (raw)
	{
		parse_line(state, &parse, raw);
		raw = get_next_line(fd);
	}
	close(fd);
	parse_finalize(state, &parse);
	free_parse(&parse);
}
