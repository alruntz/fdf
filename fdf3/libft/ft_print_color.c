/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_color.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/17 18:38:41 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/17 19:21:41 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_color(char *name, char *color)
{
	ft_putstr(color);
	ft_putstr(name);
	ft_putstr(RESET);
}
