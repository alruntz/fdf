/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstadd.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 18:23:49 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/29 20:05:02 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstadd(t_list **alst, void *content, size_t content_size)
{
	t_list	*new;

	if ((new = ft_lstnew(content, content_size)) == NULL)
		return (0);
	ft_lstlink(alst, new);
	return (1);
}
