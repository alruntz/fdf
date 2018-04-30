/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 18:23:54 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/08 18:23:54 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	if (s1 && s2)
	{
		if (!(ret = ft_strnew(sizeof(char) * ft_strlen(s1) + ft_strlen(s2))))
			return (NULL);
		while (s1[n])
		{
			ret[n] = s1[n];
			n++;
		}
		while (s2[i])
		{
			ret[n] = s2[i];
			i++;
			n++;
		}
	}
	else
		return (NULL);
	return (ret);
}
