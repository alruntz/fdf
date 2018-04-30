/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/29 14:05:05 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/29 19:44:38 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./../libft/libft.h"

typedef struct		s_vector2
{
	float			x;
	float			y;
}					t_vector2;

typedef struct		s_vector3
{
	float			x;
	float			y;
	float			z;
}					t_vector3;

typedef struct		s_fdf_options
{
	void			*win;
	void			*mlx;
	int				size_square;
	int				height;
	int				width;
	t_vector3		***matrix_points;
	t_vector3		*cam_rotation;
	int				**data_int;
	t_vector2		*position;
	int				range_height;
}					t_fdf_options;

void				print_line(t_fdf_options *options,
										t_vector3 *a, t_vector3 *b);

t_vector2			*new_vector2(float x, float y);
t_vector3			*new_vector3(float x, float y, float z);

int					key_hook(int keycode, t_fdf_options *options);
int					expose_hook(t_fdf_options *options);
t_vector3			***new_matrix(t_vector2 *pos, int **data_int,
											t_fdf_options *options);
t_fdf_options		*new_options(int size_square, char **data);
t_vector2			point3d_to2d(t_vector3 *pos, t_vector3 *rotation);
int					**convert_data(char **data, int height, int width);
void				print_fdf(t_fdf_options *options);

#endif
