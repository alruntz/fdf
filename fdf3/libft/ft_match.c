/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_match.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 18:23:50 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/08 18:23:50 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		is_end(int i, char *s2)
{
	while (s2[i])
	{
		if (s2[i] != '*')
			return (0);
		i++;
	}
	return (1);
}

static int		contain_only_stars(char *s2)
{
	int i;

	i = 0;
	while (s2[i])
	{
		if (s2[i] != '*')
			return (0);
		i++;
	}
	return (1);
}

static int		ft_recursive(char *s1, char *s2)
{
	if (s1[0] == '*')
		s1[0] = 127;
	if (!*s1 && !*s2)
		return (1);
	if (*s2 == '*' && *(s2 + 1) != '\0' && *s1 == '\0')
		return (0);
	while (*s1 == *s2)
	{
		s1++;
		s2++;
		if (*s1 == *s2)
			if (is_end(0, s2))
				return (1);
	}
	if (!is_end(0, s2) && ft_strlen((const char*)s1) == 0)
		return (0);
	if (*s1 == *s2)
		return (1);
	if (*s2 == '*')
		return (ft_recursive(s1, s2 + 1) || ft_recursive(s1 + 1, s2));
	return (0);
}

int				ft_match(char *s1, char *s2)
{
	if (*s1 != 0 && *s2 == 0)
		return (0);
	if (contain_only_stars(s2))
		return (1);
	return (ft_recursive(s1, s2));
}
