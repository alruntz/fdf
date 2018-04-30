/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 18:23:51 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/08 18:23:51 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*sdest;
	unsigned char	*ssrc;

	sdest = (unsigned char *)dest;
	ssrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		sdest[i] = ssrc[i];
		i++;
	}
	return (sdest);
}
