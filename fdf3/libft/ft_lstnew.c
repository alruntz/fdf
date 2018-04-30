/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 18:23:50 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/08 18:23:50 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *list;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (list)
	{
		list->next = NULL;
		if (!content)
		{
			list->content = NULL;
			list->content_size = 0;
		}
		else
		{
			list->content_size = content_size;
			if (!(list->content = ft_memalloc(content_size)))
				return (NULL);
			list->content = ft_memcpy(list->content, content, content_size);
		}
	}
	return (list);
}
