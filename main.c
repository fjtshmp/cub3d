#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	state;

	if (argc != 2)
	{
		printf("Usage: %s <map.cub>\n", argv[0]);
		return (1);
	}
	init(&state);
	parse(&state, argv[1]);
	exec_game(&state);
	clean_state(state);
	return (0);
}
