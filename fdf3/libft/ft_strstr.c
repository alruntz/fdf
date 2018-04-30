/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 18:23:56 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/08 18:23:56 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	const char *s1;
	const char *s2;
	const char *sbegin;

	s1 = str;
	if (ft_strlen(str) == 0 && ft_strlen(to_find) == 0)
		return ((char*)str);
	while (*s1)
	{
		s2 = to_find;
		sbegin = s1;
		while (*s1 && *to_find && *s1 == *s2)
		{
			s1++;
			s2++;
		}
		if (!*s2)
			return ((char *)sbegin);
		s1 = sbegin + 1;
	}
	return (0);
}
