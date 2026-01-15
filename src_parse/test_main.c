// #include "cub3d.h"

// static void	print_color(const char *name, const t_color *c)
// {
// 	printf("%s: R=%d G=%d B=%d value=0x%06X\n", name, c->red, c->green, c->blue,
// 		c->value & 0xFFFFFF);
// }

// static void	print_tex(const t_game *g)
// {
// 	printf("Textures:\n");
// 	printf("  NO: %s\n", g->tex[TEX_NO].file_path);
// 	printf("  SO: %s\n", g->tex[TEX_SO].file_path);
// 	printf("  WE: %s\n", g->tex[TEX_WE].file_path);
// 	printf("  EA: %s\n", g->tex[TEX_EA].file_path);
// }

// static void	print_player(const t_player *p)
// {
// 	printf("Player:\n");
// 	printf("  pos  = (%.2f, %.2f)\n", p->pos_x, p->pos_y);
// 	printf("  dir  = (%.2f, %.2f)\n", p->dir_x, p->dir_y);
// 	printf("  plane= (%.2f, %.2f)\n", p->plane_x, p->plane_y);
// }

// static void	print_map(const t_game *g)
// {
// 	int	y;

// 	printf("Map: width=%d height=%d\n", g->map.width, g->map.height);
// 	y = 0;
// 	while (g->map.grid && g->map.grid[y])
// 	{
// 		printf("|%s|\n", g->map.grid[y]);
// 		y++;
// 	}
// }

// int	main(int argc, char **argv)
// {
// 	t_game	g;

// 	ft_memset(&g, 0, sizeof(g));
// 	if (argc != 2)
// 	{
// 		printf("Usage: %s <map.cub>\n", argv[0]);
// 		return (1);
// 	}
// 	/* ここで exit 型の parse が動く（失敗時は戻らない） */
// 	parse(&g, argv[1]);
// 	/* 成功したら内容を表示 */
// 	print_tex(&g);
// 	print_color("Floor", &g.floor);
// 	print_color("Ceiling", &g.ceiling);
// 	print_player(&g.player);
// 	print_map(&g);
// 	return (0);
// }
