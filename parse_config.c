/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shfujita <shfujita@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:21:23 by shfujita          #+#    #+#             */
/*   Updated: 2026/01/12 18:21:24 by shfujita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	change_tex_to_idx(const char *s)
{
	if (!ft_strncmp(s, "NO", 2))
		return (TEX_NO);
	if (!ft_strncmp(s, "SO", 2))
		return (TEX_SO);
	if (!ft_strncmp(s, "WE", 2))
		return (TEX_WE);
	if (!ft_strncmp(s, "EA", 2))
		return (TEX_EA);
	return (-1);
}

int	is_config_line(const char *trim)
{
	if (!trim || !*trim)
		return (0);
	if ((!ft_strncmp(trim, "NO", 2) || !ft_strncmp(trim, "SO", 2)
			|| !ft_strncmp(trim, "WE", 2) || !ft_strncmp(trim, "EA", 2))
		&& is_space(trim[2]))
		return (1);
	if ((trim[0] == 'F' || trim[0] == 'C') && is_space(trim[1]))
		return (1);
	return (0);
}

static void	parse_tex_line(t_game *state, t_parse *parse, const char *trim)
{
	int			idx;
	const char	*s;
	char		*tmp;

	idx = change_tex_to_idx(trim);
	if (idx < 0)
		parse_fatal(state, parse, "invalid texture id");
	if (parse->tex_set[idx])
		parse_fatal(state, parse, "duplicate texture id");
	s = skip_space(trim + 2);
	if (*s == '\0')
		parse_fatal(state, parse, "missing texture path");
	tmp = ft_strtrim(s, " \t");
	if (!tmp)
		parse_fatal(state, parse, "malloc");
	state->tex[idx].file_path = strdup(tmp);
	free(tmp);
	if (!state->tex[idx].file_path)
		parse_fatal(state, parse, "malloc");
	parse->tex_set[idx] = 1;
}

void	parse_config_line(t_game *state, t_parse *parse, const char *trim)
{
	if (!trim || !*trim)
		parse_fatal(state, parse, "invalid config line");
	if (trim[0] == 'F' || trim[0] == 'C')
		return (parse_color_line(state, parse, trim));
	return (parse_tex_line(state, parse, trim));
}
