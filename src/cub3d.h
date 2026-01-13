#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#define TEX_NO 0
#define TEX_SO 1
#define TEX_WE 2
#define TEX_EA 3

typedef struct s_color
{
	int				red;
	int				green;
	int				blue;
	int value; // 0xRRGGBB
}					t_color;

typedef struct s_tex
{
	char			*file_path;
	void			*img_ptr;
	char			*data_addr;
	int				bpp;
	int				line_len;
	int				endian;
	int				width;
	int				height;
}					t_tex;

typedef struct s_map
{
	char **grid; // マップ文字列
	int				width;
	int				height;
}					t_map;

typedef struct s_player
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
}					t_player;

typedef struct s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*img_addr;
	int				bpp;
	int				line_len;
	int				endian;
	int				win_width;
	int				win_height;
}					t_mlx;

typedef struct s_game
{
	t_mlx			mlx;
	t_map			map;
	t_player		player;
	t_tex tex[4]; // NO, SO, WE, EA
	t_color			floor;
	t_color			ceiling;
}					t_game;

typedef enum e_parse_state
{
	ST_CFG = 0,
	ST_MAP = 1
}					t_parse_state;

typedef struct s_parse
{
	t_parse_state	state;

	int				tex_set[4];
	int				f_set;
	int				c_set;

	char			**lines;
	int				line_count;
	int				cap;
	int				max_width;

	int				player_count;
}					t_parse;

void				parse(t_game *state, const char *path);
void				parse_fatal(t_game *g, t_parse *p, const char *msg);
int					is_blank(const char *s);
char				*dup_strip_eol(const char *s);
int					is_space(char c);
const char			*skip_space(const char *s);
void				validate_map(t_game *g, t_parse *p);
int					is_map_line(const char *line);
void				parse_line(t_game *state, t_parse *parse, char *raw_line);
void				parse_config_line(t_game *state, t_parse *parse,
						const char *trim);
int					is_config_line(const char *trim);
void				parse_color_line(t_game *state, t_parse *parse,
						const char *trimed_line);
void				map_push(t_game *state, t_parse *parse, const char *line);
void				free_tex_paths(t_game *g);
void				free_map_grid(t_game *g);
void				free_parse(t_parse *p);
void				finalize_parse(t_game *g, t_parse *p);
void				finalize_map_grid(t_game *state, t_parse *parse);
void				set_map_player(t_game *state, t_parse *parse);
void				cleanup_state(t_game *state);
