/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 18:23:55 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/08 18:23:55 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*sdst;
	const char	*ssrc;
	size_t		n;
	size_t		len_sdst;

	n = dstsize;
	ssrc = src;
	sdst = dst;
	while (*sdst && n--)
		sdst++;
	len_sdst = sdst - dst;
	n = dstsize - len_sdst;
	if (!n)
		return (len_sdst + ft_strlen((char *)src));
	while (*ssrc)
	{
		if (n != 1)
		{
			*sdst++ = *ssrc;
			n--;
		}
		ssrc++;
	}
	*sdst = '\0';
	return (len_sdst + (ssrc - src));
}
