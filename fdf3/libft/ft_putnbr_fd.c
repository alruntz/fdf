/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_fd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 18:23:52 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/08 18:23:52 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long l;

	l = (long)n;
	if (l < 0)
	{
		ft_putchar_fd('-', fd);
		l = l * -1;
	}
	if (l <= 9)
		ft_putchar_fd(l + '0', fd);
	else
	{
		ft_putnbr_fd(l / 10, fd);
		ft_putchar_fd(l % 10 + '0', fd);
	}
}
