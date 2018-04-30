/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 18:23:49 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/08 18:23:49 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;
	t_list *ttemp;

	temp = *alst;
	if (temp)
	{
		while (temp)
		{
			ttemp = temp->next;
			del(temp->content, temp->content_size);
			free(temp);
			temp = ttemp;
		}
		*alst = NULL;
	}
}
