#include "cub3d.h"

static int	is_map_char(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S'
		|| c == 'E' || c == 'W' || c == ' ' || c == '\t');
}

int	is_map_line(const char *line)
{
	int	has_tile;

	if (!line || !*line)
		return (0);
	has_tile = 0;
	while (*line)
	{
		if (!is_map_char(*line))
			return (0);
		if (*line == '0' || *line == '1'
			|| *line == 'N' || *line == 'S'
			|| *line == 'E' || *line == 'W')
			has_tile = 1;
		line++;
	}
	return (has_tile);
}

void	map_finalize_grid(t_game *g, t_parse *p)
{
	int		y;
	int		x;
	int		w;
	char	*row;
	char	*src;

	g->map.height = p->line_count;
	g->map.width = p->max_width;
	g->map.grid = (char **)malloc(sizeof(char *) * (g->map.height + 1));
	if (!g->map.grid)
		parse_fatal(g, p, "malloc");
	y = 0;
	while (y < g->map.height)
	{
		row = (char *)malloc((size_t)g->map.width + 1);
		if (!row)
			parse_fatal(g, p, "malloc");
		x = 0;
		while (x < g->map.width)
			row[x++] = ' ';
		row[g->map.width] = '\0';
		src = p->lines[y];
		w = (int)ft_strlen(src);
		x = 0;
		while (x < w && x < g->map.width)
		{
			row[x] = src[x];
			if (row[x] == '\t')
				row[x] = ' ';
			x++;
		}
		g->map.grid[y] = row;
		y++;
	}
	g->map.grid[g->map.height] = NULL;
}

static void	set_dir_plane(t_game *g, char c)
{
	const double	pn = 0.66;

	if (c == 'N')
	{
		g->player.dir_x = 0;
		g->player.dir_y = -1;
		g->player.plane_x = pn;
		g->player.plane_y = 0;
	}
	else if (c == 'S')
	{
		g->player.dir_x = 0;
		g->player.dir_y = 1;
		g->player.plane_x = -pn;
		g->player.plane_y = 0;
	}
	else if (c == 'E')
	{
		g->player.dir_x = 1;
		g->player.dir_y = 0;
		g->player.plane_x = 0;
		g->player.plane_y = pn;
	}
	else if (c == 'W')
	{
		g->player.dir_x = -1;
		g->player.dir_y = 0;
		g->player.plane_x = 0;
		g->player.plane_y = -pn;
	}
}

void	map_set_player(t_game *g, t_parse *p)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	while (y < g->map.height)
	{
		x = 0;
		while (x < g->map.width)
		{
			c = g->map.grid[y][x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				p->player_count++;
				if (p->player_count > 1)
					parse_fatal(g, p, "multiple players in map");
				g->player.pos_x = (double)x + 0.5;
				g->player.pos_y = (double)y + 0.5;
				set_dir_plane(g, c);
				g->map.grid[y][x] = '0';
			}
			x++;
		}
		y++;
	}
	if (p->player_count != 1)
		parse_fatal(g, p, "player not found in map");
}

/*
** void隣接チェックで閉じを検証
** - '0' が境界にいたらアウト
** - '0' が ' ' に接していたらアウト
** - map_validate は map_set_player 後に呼ぶ想定（NSEWは残っていない）
*/
static void	check_floor_cell_or_die(t_game *g, t_parse *p, int y, int x)
{
	if (y <= 0 || x <= 0 || y >= g->map.height - 1 || x >= g->map.width - 1)
		parse_fatal(g, p, "map not closed (floor on border)");
	if (g->map.grid[y - 1][x] == ' ' || g->map.grid[y + 1][x] == ' '
		|| g->map.grid[y][x - 1] == ' ' || g->map.grid[y][x + 1] == ' ')
		parse_fatal(g, p, "map not closed (floor touches void)");
}

void	map_validate(t_game *g, t_parse *p)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	while (y < g->map.height)
	{
		x = 0;
		while (x < g->map.width)
		{
			c = g->map.grid[y][x];
			if (!(c == '0' || c == '1' || c == ' '))
				parse_fatal(g, p, "invalid char in map");
			if (c == '0')
				check_floor_cell_or_die(g, p, y, x);
			x++;
		}
		y++;
	}
}