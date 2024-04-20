#include "dino.h"

int	handle_key(int key, void *param)
{
	t_dino *dino;

	dino = (t_dino *)param;
	if (key == 53)
		exit_program(dino);
	else if (key == UP)
		dino->d_y -= 5;
	return (0);
}
