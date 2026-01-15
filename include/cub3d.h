#ifndef CUB3D_H
# define CUB3D_H

# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIN_WIDTH 640
# define WIN_HEIGHT 480

/* ===== texture index ===== */
# define TEX_NO 0
# define TEX_SO 1
# define TEX_WE 2
# define TEX_EA 3

/* ===== key codes (X11想定) ===== */
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307

/* ===== movement params ===== */
# define MOVE_SPEED 0.01
# define ROT_SPEED 0.01

/* ===================== types ===================== */

typedef struct s_color
{
	int				red;
	int				green;
	int				blue;
	int value; /* 0xRRGGBB */
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
	char **grid; /* map文字列（矩形化済みを想定） */
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

typedef struct s_key
{
	int				w;
	int				a;
	int				s;
	int				d;
	int				left;
	int				right;
}					t_key;

typedef struct s_game
{
	t_mlx			mlx;
	t_map			map;
	t_player		player;

	t_tex tex[4]; /* NO, SO, WE, EA */
	t_color			floor;
	t_color			ceiling;

	t_key keys; /* ループで参照するキー状態 */
}					t_game;

typedef struct s_ray
{
	double			camera_x;

	double			dir_x;
	double			dir_y;

	int				map_x;
	int				map_y;

	double			side_dist_x;
	double			side_dist_y;

	double			delta_dist_x;
	double			delta_dist_y;

	double			perp_wall_dist;

	int				step_x;
	int				step_y;

	int				hit;
	int				side;

	int				line_height;
	int				draw_start;
	int				draw_end;
}					t_ray;

typedef struct s_draw
{
	t_tex *tex; /* 使用するテクスチャ */
	int				tex_x;
	int				tex_y;
	double			step;
	double			tex_pos;
}					t_draw;

/* ===================== parser types ===================== */

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

/* ===================== error / exit ===================== */

void				print_error(char *msg);
int					exit_game(void *state);

/* ===================== init / run ===================== */

int					exec_game(t_game *state);
int					load_textures(t_game *state);

/* ===================== movement ===================== */

void				move_forward(t_game *state);
void				move_backward(t_game *state);
void				move_right(t_game *state);
void				move_left(t_game *state);
void				rotate_left(t_game *state);
void				rotate_right(t_game *state);

/* ===================== rendering (raycasting) ===================== */

void				cast_rays(t_game *state);
void				init_ray(t_game *state, t_ray *ray, int x);
void				init_dda(t_game *state, t_ray *ray);
void				draw_floor_ceiling(t_game *state);
void				draw_vertical_stripe(t_game *state, t_ray *ray, int x);
void				init_draw_tex(t_game *state, t_ray *ray, t_draw *d);

/* ===================== parsing ===================== */

void				parse(t_game *state, const char *path);
void				parse_fatal(t_game *state, t_parse *parse, const char *msg);

int					is_blank(const char *s);
int					is_space(char c);
const char			*skip_space(const char *s);
char				*dup_strip_eol(const char *s);

int					is_config_line(const char *trim);
void				parse_config_line(t_game *state, t_parse *parse,
						const char *trim);
void				parse_color_line(t_game *state, t_parse *parse,
						const char *trim_line);

int					is_map_line(const char *line);
void				parse_line(t_game *state, t_parse *parse, char *raw_line);
void				map_push(t_game *state, t_parse *parse, const char *line);

void				validate_map(t_game *state, t_parse *parse);
void				finalize_parse(t_game *state, t_parse *parse);
void				finalize_map_grid(t_game *state, t_parse *parse);
void				set_map_player(t_game *state, t_parse *parse);

/* ===================== cleanup ===================== */

void				free_tex_paths(t_game *state);
void				free_map_grid(t_game *state);
void				free_parse(t_parse *parse);
void				cleanup_state(t_game *state);

#endif
