/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 18:23:49 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/08 18:23:49 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static size_t		check_size_num(int n)
{
	if (n < 0)
		return (n == -2147483648 ? 11 : 1 + check_size_num(-n));
	return (n < 10 ? 1 : 1 + check_size_num(n / 10));
}

char				*ft_itoa(int n)
{
	char	*nbr;
	long	nb;
	size_t	len;

	nb = n;
	nb = n < 0 ? -nb : nb;
	len = check_size_num(n);
	if (!(nbr = ft_strnew(sizeof(char) * len)))
		return (NULL);
	while (len--)
	{
		nbr[len] = nb % 10 + '0';
		nb /= 10;
	}
	if (n < 0)
		nbr[0] = '-';
	return (nbr);
}
