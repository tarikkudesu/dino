#include "dino.h"

void	init_dino(t_dino *dino)
{
	dino->b_x = 0;
	dino->d_y = 295;
	dino->direction = false;
	dino->run = 0;
	dino->mlx = mlx_init();
	if (!dino->mlx)
		(ft_putendl_fd(MLX_INIT, 2), exit(EXIT_FAILURE));
	dino->win = mlx_new_window(dino->mlx, WIDTH, HEIGHT, "dino");
	if (!dino->win)
		(ft_putendl_fd(MLX_WIN, 2), exit(EXIT_FAILURE));
}

void	init_xpms(t_dino *dino)
{
	t_p	point;

	dino->dino = mlx_xpm_file_to_image(dino->mlx, \
	"assets/dino.xpm", &point.h, &point.w);
	if (!dino->dino)
		(ft_putendl_fd(MLX_XPM, 2), exit(EXIT_FAILURE));	
	/* dino->dino_cloud = mlx_xpm_file_to_image(dino->mlx, \ */
	/* "assets/dino_cloud.xpm", &point.h, &point.w); */
	/* if (!dino->dino_cloud) */
	/* 	(ft_putendl_fd(MLX_XPM, 2), exit(EXIT_FAILURE)); */	
	dino->dino_dead = mlx_xpm_file_to_image(dino->mlx, \
	"assets/dino_dead.xpm", &point.h, &point.w);
	if (!dino->dino_dead)
		(ft_putendl_fd(MLX_XPM, 2), exit(EXIT_FAILURE));	
	/* dino->dino_road = mlx_xpm_file_to_image(dino->mlx, \ */
	/* "assets/dino_road.xpm", &point.h, &point.w); */
	/* if (!dino->dino_road) */
	/* 	(ft_putendl_fd(MLX_XPM, 2), exit(EXIT_FAILURE)); */	
	dino->dino_run1 = mlx_xpm_file_to_image(dino->mlx, \
	"assets/dino_run1.xpm", &point.h, &point.w);
	if (!dino->dino_run1)
		(ft_putendl_fd(MLX_XPM, 2), exit(EXIT_FAILURE));	
	/* dino->dino_run2 = mlx_xpm_file_to_image(dino->mlx, \ */
	/* "assets/dino_run2.xpm", &point.h, &point.w); */
	/* if (!dino->dino_run2) */
	/* 	(ft_putendl_fd(MLX_XPM, 2), exit(EXIT_FAILURE)); */	
	/* dino->dino_zoro = mlx_xpm_file_to_image(dino->mlx, \ */
	/* "assets/dino_zoro.xpm", &point.h, &point.w); */
	/* if (!dino->dino_zoro) */
	/* 	(ft_putendl_fd(MLX_XPM, 2), exit(EXIT_FAILURE)); */	
	/* dino->dino_zoro1 = mlx_xpm_file_to_image(dino->mlx, \ */
	/* "assets/dino_zoro1.xpm", &point.h, &point.w); */
	/* if (!dino->dino_zoro1) */
	/* 	(ft_putendl_fd(MLX_XPM, 2), exit(EXIT_FAILURE)); */	
	dino->background = mlx_xpm_file_to_image(dino->mlx, \
	"assets/background.xpm", &point.h, &point.w);
	if (!dino->background)
		(ft_putendl_fd(MLX_XPM, 2), exit(EXIT_FAILURE));	
}

int	update(void *param)
{
	t_dino	*dino;

	dino = (t_dino *)param;
	mlx_put_image_to_window(dino->mlx, dino->win, dino->background, dino->b_x, 0);
	dino->b_x -= 5;
	if (dino->b_x == -3000)
		dino->b_x = 0;

	/* if (dino->run < 100) */
	/* { */
		/* mlx_put_image_to_window(dino->mlx, dino->win, dino->dino_run1, 40, dino->d_y); */
		/* dino->run++; */
	/* } */
	/* else if (dino->run >= 0) */
	/* { */
		mlx_put_image_to_window(dino->mlx, dino->win, dino->dino, 40, dino->d_y);
		/* dino->run--; */
	/* } */
	if (dino->d_y != 295 && dino->direction == false)
		dino->d_y -= 5;
	if (dino->d_y == 205)
		dino->direction = true;
	if (dino->d_y != 295 && dino->direction == true)
		dino->d_y += 5;
	if (dino->d_y == 295)
		dino->direction = false;
	return (0);
}

void	start_dino(t_dino *dino)
{
	init_xpms(dino);
	/* mlx_put_image_to_window(dino->mlx, dino->win, dino->dino_dead, 0, 100); */
	/* mlx_put_image_to_window(dino->mlx, dino->win, dino->dino, 100, 400); */
	/* mlx_put_image_to_window(dino->mlx, dino->win, dino->dino_road, 0, 400); */
	mlx_hook(dino->win, 2, 0, &handle_key, dino);
	/* mlx_hook(fdf->win, 4, 0, &handle_mouse, fdf); */
	/* mlx_hook(fdf->win, 5, 0, &handle_mouse_release, fdf); */
	/* mlx_hook(fdf->win, 6, 0, &handle_mouse_move, fdf); */
	mlx_loop_hook(dino->mlx, &update, dino);
	mlx_hook(dino->win, 17, 0, &exit_program, dino);
	mlx_loop(dino->mlx);
}

int	main()
{
	t_dino	dino;

	init_dino(&dino);
	start_dino(&dino);
}
