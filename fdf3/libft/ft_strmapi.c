/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 18:23:55 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/08 18:23:55 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ret;

	if (s)
	{
		if (!(ret = ft_strnew(sizeof(char) * ft_strlen(s))))
			return (NULL);
		i = 0;
		while (s[i])
		{
			ret[i] = f(i, s[i]);
			i++;
		}
	}
	else
		return (NULL);
	return (ret);
}
