/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_merge_str.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 18:23:51 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/08 18:30:35 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_merge_str(char *s1, char *s2)
{
	char	*new;

	if (s1 == NULL)
		return (ft_strdup(s2));
	if (!(new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	ft_strcpy(new, s1);
	return (ft_strcat(new, s2));
}
