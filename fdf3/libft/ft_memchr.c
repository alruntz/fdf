/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 18:23:50 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/08 18:23:50 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp_s;
	size_t			i;
	unsigned char	tmp_c;

	i = 0;
	tmp_s = (unsigned char *)s;
	tmp_c = (unsigned char)c;
	while (i < n)
	{
		if (tmp_s[i] == tmp_c)
			return (tmp_s + i);
		i++;
	}
	return (NULL);
}
