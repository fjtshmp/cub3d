#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	state;

	if (argc != 2)
	{
		printf("Usage: %s <map.cub>\n", argv[0]);
		return (1);
	}
	ft_memset(&state, 0, sizeof(state));
	parse(&state, argv[1]);
	printf("parse_ok\n");
	exec_game(&state);
	cleanup_state(&state);
	return (0);
}
