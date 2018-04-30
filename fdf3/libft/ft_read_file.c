/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_read_file.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 18:23:53 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/17 19:21:15 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "libft.h"

t_reader			ft_read_file(int fd, int buff_size)
{
	int				rd;
	char			buf[buff_size + 1];
	char			*tmp;
	char			*str;
	t_reader		ret;

	str = NULL;
	while ((rd = read(fd, buf, buff_size)))
	{
		if (rd == -1)
			break ;
		tmp = str;
		buf[rd] = '\0';
		str = ft_merge_str(str, buf);
		free(tmp);
	}
	ret.rd = rd;
	ret.str = str;
	return (ret);
}
