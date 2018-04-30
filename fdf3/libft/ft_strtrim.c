/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 18:23:57 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/08 18:23:57 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	is_end(char const *s, size_t i)
{
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

static char	*create_str(char const *s, size_t start, size_t end)
{
	char	*ret;
	size_t	i;

	i = 0;
	if (!(ret = (ft_strnew(sizeof(char) * end - start))))
		return (NULL);
	while (start < end)
	{
		ret[i] = s[start];
		start++;
		i++;
	}
	return (ret);
}

char		*ft_strtrim(char const *s)
{
	size_t start;
	size_t end;
	size_t i;

	start = 0;
	i = 0;
	if (s)
	{
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		{
			start++;
			i++;
		}
		end = start;
		while (s[i])
		{
			if (!is_end(s, end))
				end++;
			i++;
		}
	}
	else
		return (NULL);
	return (create_str(s, start, end));
}
