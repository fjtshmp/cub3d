#include "cub3d.h"

void	parse_line(t_game *g, t_parse *p, char *raw_line)
{
	char	*line;
	char	*trim;

	line = dup_strip_eol(raw_line);
	free(raw_line);
	if (!line)
		parse_fatal(g, p, "malloc");
	if (is_blank(line))
	{
		if (p->state == ST_CFG)
			return (free(line));
		free(line);
		parse_fatal(g, p, "blank line in map");
	}
	trim = ft_strtrim(line, " \t");
	if (!trim)
		return (free(line), parse_fatal(g, p, "malloc"));
	if (p->state == ST_CFG)
	{
		if (is_config_line(trim))
			return (parse_config_line(g, p, trim), free(trim), free(line));
		if (is_map_line(line))
			return (p->state = ST_MAP, map_push(g, p, line), free(trim), free(line));
		free(trim);
		free(line);
		parse_fatal(g, p, "invalid line before map");
	}
	if (!is_map_line(line))
		return (free(trim), free(line), parse_fatal(g, p, "invalid map line"));
	map_push(g, p, line);
	free(trim);
	free(line);
}