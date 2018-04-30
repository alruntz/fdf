/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/22 13:58:39 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/29 20:07:52 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include "./../includes/fdf.h"
#include <math.h>
#include <fcntl.h>

void	init_fdf(t_fdf_options *options, int **data_int)
{
	void *mlx;
	void *win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1500, 1500, "mlx 42");
	mlx_expose_hook(win, expose_hook, options);
	mlx_key_hook(win, key_hook, options);
	options->win = win;
	options->mlx = mlx;
	options->data_int = data_int;
	options->range_height = 1;
	options->position = new_vector2(150, 150);
	options->matrix_points =
		new_matrix(new_vector2(150, 150), data_int, options);
	print_fdf(options);
	mlx_loop(mlx);
}

int		main(int argc, char **argv)
{
	char			**data;
	int				**data_int;
	int				fd;
	t_fdf_options	*options;

	if (argc != 2)
		ft_putstr("usage : ./fdf map.fdf");
	else if ((fd = (open(argv[1], O_RDONLY))))
	{
		if (!(data = ft_strsplit(ft_read_file(fd, 4096).str, '\n')))
		{
			ft_putstr("le fichier transmis est invalide");
			return (0);
		}
		options = new_options(5, data);
		options->cam_rotation = new_vector3(50, -100, 150);
		if ((data_int = convert_data(data, options->height, options->width)))
			init_fdf(options, data_int);
		else
			ft_putstr("le fichier transmis est invalide");
	}
	return (0);
}
