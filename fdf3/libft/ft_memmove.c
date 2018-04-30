/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 18:23:51 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/08 18:23:51 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char *sdest;
	char *ssrc;

	sdest = (char *)dest;
	ssrc = (char *)src;
	if (dest < src)
		ft_memcpy(dest, src, n);
	else
	{
		while (n--)
			sdest[n] = ssrc[n];
	}
	return (dest);
}
