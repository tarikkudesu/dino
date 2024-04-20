#ifndef DINO_H
# define DINO_H

# include "/Users/tamehri/local/ta_lib/libt.h"
# include "/usr/local/include/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <errno.h>
# include <stdbool.h>

# define WIDTH		1000
# define HEIGHT		600
# define UP			126
# define DOWN		125

# define MLX_XPM	"Error : mlx_xpm_file_to_image"
# define MLX_ADD	"Error : mlx_get_data_addr"
# define MLX_WIN	"Error : mlx_new_window"
# define MLX_IMG	"Error : mlx_new_image"
# define MLX_INIT	"Error : mlx_init error"
# define ERR_ARG	"Error : no argument required"

typedef struct s_dino	t_dino;
typedef struct s_p		t_p;

int	exit_program(void *param);
int	handle_key(int key, void *param);

struct s_dino
{
	bool	direction;
	int		run;
	int		b_x;
	int		d_y;
	void	*mlx;
	void	*win;

	void	*dino;
	void	*dino_cloud;
	void	*dino_road;
	void	*dino_dead;
	void	*dino_run1;
	void	*dino_run2;
	void	*dino_zoro;
	void	*dino_zoro1;
	void	*background;
};

struct s_p
{
	int		w;
	int		h;
};

#endif

