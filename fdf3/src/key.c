/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/29 14:06:02 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/29 17:57:37 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../includes/fdf.h"
#include "mlx.h"
#include <stdlib.h>

static void		key_move(int keycode, t_fdf_options *options)
{
	if (keycode == 1)
		options->size_square++;
	if (keycode == 2)
		options->size_square--;
	if (keycode == 3)
		options->cam_rotation->x++;
	if (keycode == 4)
		options->cam_rotation->x--;
	if (keycode == 5)
		options->cam_rotation->y++;
	if (keycode == 6)
		options->cam_rotation->y--;
	if (keycode == 7)
		options->position->x++;
	if (keycode == 8)
		options->position->x--;
	if (keycode == 9)
		options->position->y++;
	if (keycode == 10)
		options->position->y--;
	if (keycode == 12)
		options->range_height++;
	if (keycode == 13)
		options->range_height--;
}

int				key_hook(int keycode, t_fdf_options *options)
{
	if (keycode == 53)
	{
		mlx_destroy_window(options->mlx, options->win);
		free(options);
		exit(0);
	}
	else if (keycode >= 1 && keycode <= 13)
	{
		free(options->matrix_points);
		key_move(keycode, options);
		options->matrix_points =
			new_matrix(options->position, options->data_int, options);
		print_fdf(options);
	}
	return (0);
}

int				expose_hook(t_fdf_options *options)
{
	if (options == NULL)
		;
	return (0);
}
