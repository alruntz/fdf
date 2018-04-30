/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 18:23:56 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/08 18:23:56 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t n;
	size_t i;

	n = ft_strlen(needle);
	if (n == 0)
		return ((char *)haystack);
	while (len != 0 && *haystack)
	{
		i = 0;
		while (i < len && i < n && *(haystack + i) == *(needle + i))
			i++;
		if (i == n)
			return ((char *)(haystack));
		haystack++;
		len--;
	}
	return (NULL);
}
