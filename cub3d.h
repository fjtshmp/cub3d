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
