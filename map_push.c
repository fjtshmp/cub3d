#include "cub3d.h"

static void	add_lines(t_game *state, t_parse *parse)
{
	char	**new_parse;
	int		new_cap;
	int		i;

	new_cap = parse->cap;
	if (new_cap == 0)
		new_cap = 8;
	else
		new_cap *= 2;
	new_parse = (char **)malloc(sizeof(char *) * new_cap);
	if (!new_parse)
		parse_fatal(state, parse, "malloc");
	i = 0;
	while (i < parse->line_count)
	{
		new_parse[i] = parse->lines[i];
		i++;
	}
	free(parse->lines);
	parse->lines = new_parse;
	parse->cap = new_cap;
}

void	map_push(t_game *state, t_parse *parse, const char *line)
{
	char	*dup;
	int		len;

	if (parse->line_count == parse->cap)
		add_lines(state, parse);
	dup = ft_strdup(line);
	if (!dup)
		parse_fatal(state, parse, "malloc");
	parse->lines[parse->line_count++] = dup;
	len = (int)ft_strlen(dup);
	if (len > parse->max_width)
		parse->max_width = len;
}