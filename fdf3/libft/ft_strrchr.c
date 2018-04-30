/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 18:23:56 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/08 18:23:56 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	get_nextc(char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

char		*ft_strrchr(const char *s, int c)
{
	char *ret;

	ret = (char *)s;
	while (*ret)
	{
		if (*ret == c)
			if (!(get_nextc(ret + 1, c)))
				return (ret);
		ret++;
	}
	if (!c)
		return (ret);
	return (NULL);
}
