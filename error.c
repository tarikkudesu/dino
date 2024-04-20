#include "dino.h"

int	exit_program(void *param)
{
	t_dino	*dino;

	dino = (t_dino *)param;
	exit(0);
}

