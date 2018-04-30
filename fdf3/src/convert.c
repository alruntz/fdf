/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   convert.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 13:16:06 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/29 20:00:59 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

t_vector2	point3d_to2d(t_vector3 *pos, t_vector3 *rotation)
{
	t_vector2 ret;

	ret.x = pos->x - rotation->x * pos->z / rotation->z;
	ret.y = pos->y - rotation->y * pos->z / rotation->z;
	return (ret);
}

int			**convert_data(char **data, int height, int width)
{
	int		i;
	int		j;
	int		**ret;
	char	**split;

	if (!(ret = (int **)malloc(sizeof(int *) * height)))
		return (NULL);
	i = 0;
	while (i < height)
	{
		ret[i] = malloc(sizeof(int) * width);
		split = ft_strsplit(data[i], ' ');
		j = 0;
		while (split[j])
		{
			ret[i][j] = ft_atoi(split[j]);
			j++;
		}
		i++;
	}
	return (ret);
}
