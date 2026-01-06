
#define TEX_NO 0
#define TEX_SO 1
#define TEX_WE 2
#define TEX_EA 3
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_LEFT 123
#define KEY_RIGHT 124
#define KEY_ESC 53
#define MOVE_SPEED 0.1
#define ROT_SPEED 0.05

typedef struct s_color
{
	int			red;
	int			green;
	int			blue;
	int value; // 0xRRGGBB にしておくと楽
}				t_color;

typedef struct s_tex
{
	char		*file_path;
	void		*img_ptr;
	char		*data_addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			width;
	int			height;
}				t_tex;

typedef struct s_map
{
	char **grid; // マップ文字列
	int			width;
	int			height;
}				t_map;

typedef struct s_player
{
	// x,y座標上のプレイヤーの位置
	double		pos_x;
	double		pos_y;
	//プレイヤーの向きを表すベクトル
	double		dir_x;
	double		dir_y;
	//プレイヤーの向きベクトルと直行するベクトル
	double		plane_x;
	double		plane_y;
}				t_player;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*img_addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			win_width;
	int			win_height;
}				t_mlx;

typedef struct s_game
{
	t_mlx		mlx;
	t_map		map;
	t_player	player;
	t_tex tex[4]; // NO, SO, WE, EA
	t_color		floor;
	t_color		ceiling;
}				t_game;

typedef struct s_ray
{
	//スクリーン上を左から右へ動く座標上の点x（-1~1）
	double		camera_x;
	//光の方向ベクトル
	double		dir_x;
	double		dir_y;
	//進んでいる光のマップ上の座標
	int			map_x;
	int			map_y;
	//次のグリッドに達するのに必要なレイ方向の距離
	double		side_dist_x;
	double		side_dist_y;
	// x,y方向に1.0進めるのに必要なレイ方向の距離
	double		delta_dist_x;
	double		delta_dist_y;
	//魚眼補正後の壁までの距離
	double		perp_wall_dist;
	//光が進む方向　-1 or 1
	int			step_x;
	int			step_y;
	//光が壁にあたったかどうかを表すフラグ
	int			hit;
	//光がどの面にあたったか縦の壁=0, 横の壁=1
	int			side;
	//画面上に描く壁の高さ
	int			line_height;
	//壁を描画する縦方向の範囲
	int			draw_start;
	int			draw_end;
}				t_ray;

typedef struct s_draw
{
	t_tex *tex;     // 使用するテクスチャ（NO / SO / WE / EA）
	int tex_x;      // テクスチャのX座標
	int tex_y;      // テクスチャのY座標
	double step;    // 画面1pxあたりのテクスチャYの進み量
	double tex_pos; // 現在参照しているテクスチャY位置（double）
}				t_draw;

void			exit_game(t_game *state);
int				load_textures(t_game *state);

int				exec_game(t_game *state);

void			move_forward(t_game *state);
void			move_backward(t_game *state);
void			move_right(t_game *state);
void			move_left(t_game *state);
void			rotate_left(t_game *state);
void			rotate_right(t_game *state);

void			cast_rays(t_game *state);
void			init_dda(t_game *state, t_ray *ray);
void			init_ray(t_game *state, t_ray *ray, int x);
void			draw_floor_ceiling(t_game *state);
void			draw_vertical_stripe(t_game *state, t_ray *ray, int x);
void			init_draw_tex(t_game *state, t_ray *ray, t_draw *d);
