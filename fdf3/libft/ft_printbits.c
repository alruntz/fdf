/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printbits.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 18:23:52 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/08 18:23:52 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>

void	ft_printbits(unsigned char octet)
{
	int		n;

	n = 128;
	while (n != 1)
	{
		if (octet / n == 1)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		octet %= n;
		n /= 2;
	}
	if (octet == 1)
		write(1, "1", 1);
	else
		write(1, "0", 1);
}
