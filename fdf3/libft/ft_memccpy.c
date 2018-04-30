/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 18:23:50 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/08 18:23:50 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*ssrc;
	unsigned char	*sdest;
	size_t			i;

	ssrc = (unsigned char *)src;
	sdest = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		sdest[i] = ssrc[i];
		if (ssrc[i] == (unsigned char)c)
			return (sdest + (i + 1));
		i++;
	}
	return (NULL);
}
