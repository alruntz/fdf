/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 18:23:50 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/08 18:23:50 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list *ret;
	t_list *tmp;

	tmp = f(lst);
	ret = tmp;
	if (lst)
	{
		while (lst->next)
		{
			lst = lst->next;
			if (!(tmp->next = f(lst)))
			{
				free(tmp->next);
				return (NULL);
			}
			tmp = tmp->next;
		}
	}
	return (ret);
}
