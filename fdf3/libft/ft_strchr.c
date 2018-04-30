/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 18:23:53 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/08 18:23:53 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *ret;

	ret = (char *)s;
	while (*ret)
	{
		if (*ret == c)
			return (ret);
		ret++;
	}
	if (!c)
		return (ret);
	return (NULL);
}
