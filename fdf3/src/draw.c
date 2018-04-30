/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/22 14:14:04 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/29 17:57:17 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../includes/fdf.h"
#include "mlx.h"
#include <math.h>

static void				drawline_point(t_fdf_options *options, int step,
										t_vector3 *a, t_vector3 *b)
{
	int				i;
	double			xi;
	double			yi;
	t_vector2		pix;

	pix.x = a->x;
	pix.y = a->z;
	xi = (double)(b->x - a->x) / step;
	yi = (double)(b->z - a->z) / step;
	i = -1;
	while (++i <= step)
	{
		mlx_pixel_put(options->mlx, options->win, pix.x, pix.y, 0x0AACCFF);
		pix.x = a->x + round((double)i * xi);
		pix.y = a->z + round((double)i * yi);
	}
}

void					print_line(t_fdf_options *options, t_vector3 *a,
												t_vector3 *b)
{
	int	step;

	if (fabs(a->x - b->x) <= fabs(a->y - b->y))
		step = 1 + fabs(a->z - b->z);
	else
		step = 1 + fabs(a->x - b->x);
	drawline_point(options, step, a, b);
}

void					print_fdf(t_fdf_options *options)
{
	int i;
	int j;

	i = 0;
	mlx_clear_window(options->mlx, options->win);
	while (options->matrix_points[i])
	{
		j = 0;
		while (options->matrix_points[i][j])
		{
			if (options->matrix_points[i][j + 1])
				print_line(options, options->matrix_points[i][j],
						options->matrix_points[i][j + 1]);
			if (i < options->height - 1)
				print_line(options, options->matrix_points[i + 1][j],
						options->matrix_points[i][j]);
			j++;
		}
		i++;
	}
}
