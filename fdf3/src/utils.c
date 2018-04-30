/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/22 14:04:58 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/29 19:44:18 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

t_vector2		*new_vector2(float x, float y)
{
	t_vector2 *ret;

	ret = malloc(sizeof(t_vector2));
	ret->x = x;
	ret->y = y;
	return (ret);
}

t_vector3		*new_vector3(float x, float y, float z)
{
	t_vector3 *ret;

	ret = malloc(sizeof(t_vector3));
	ret->x = x;
	ret->y = y;
	ret->z = z;
	return (ret);
}

t_fdf_options	*new_options(int size_square, char **data)
{
	t_fdf_options	*ret;
	int				i;
	int				j;
	int				jj;

	i = -1;
	jj = 0;
	if (!(ret = malloc(sizeof(t_fdf_options))))
		return (NULL);
	while (data[++i])
	{
		j = -1;
		if (i == 0)
			while (data[i][++j])
				if (data[i][j] == ' ' && data[i][j + 1] &&
						data[i][j + 1] != ' ')
					jj++;
	}
	ret->size_square = size_square;
	ret->height = i - 1;
	ret->width = jj;
	return (ret);
}
