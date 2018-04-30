/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   matrix.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/29 13:52:20 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/29 19:50:59 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../includes/fdf.h"
#include <stdlib.h>

static t_vector3	***malloc_matrix(t_fdf_options *options)
{
	int			i;
	int			j;
	t_vector3	***ret;

	i = 0;
	ret = malloc(sizeof(t_vector3 **) * options->height + 1);
	while (i < options->height)
	{
		j = 0;
		while (j < options->width)
			j++;
		ret[i] = malloc(sizeof(t_vector3 *) * j + 1);
		i++;
	}
	return (ret);
}

static void			init_pos(t_vector2 *pos_current,
		t_vector2 *pos, t_fdf_options *options)
{
	pos_current->x = pos->x;
	pos_current->y += options->size_square;
}

t_vector3			***new_matrix(t_vector2 *pos, int **data_int,
												t_fdf_options *options)
{
	t_vector3	***ret;
	t_vector2	*pos_current;
	t_vector2	point2d;
	int			i;
	int			j;

	pos_current = new_vector2(pos->x, pos->y);
	ret = malloc_matrix(options);
	i = -1;
	while (++i < options->height)
	{
		j = -1;
		while (++j < options->width)
		{
			point2d = point3d_to2d(new_vector3(pos_current->x, 0,
				(pos_current->y) - data_int[i][j] * options->range_height),
					options->cam_rotation);
			ret[i][j] = new_vector3(point2d.x, data_int[i][j], point2d.y);
			pos_current->x += options->size_square;
		}
		ret[i][j] = NULL;
		init_pos(pos_current, pos, options);
	}
	ret[i] = NULL;
	return (ret);
}
