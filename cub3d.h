typedef struct s_color {
	int r;
	int g;
	int b;
	int value; // 0xRRGGBB にしておくと楽
}	t_color;

typedef struct s_tex {
	char	*path;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		w;
	int		h;
}	t_tex;

typedef struct s_map {
	char	**grid;   // マップ文字列
	int		width;
	int		height;
}	t_map;

typedef struct s_player {
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_mlx {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		win_w;
	int		win_h;
}	t_mlx;

typedef struct s_game {
	t_mlx		mlx;
	t_map		map;
	t_player	player;
	t_tex		tex[4]; // NO, SO, WE, EA
	t_color		floor;
	t_color		ceiling;
}	t_game;
