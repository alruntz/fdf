/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alruntz <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/08 18:23:56 by alruntz      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/08 18:23:56 by alruntz     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	get_num_words(char const *str, char c)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (str[i])
	{
		if (str[i] != c)
			ret++;
		while (str[i] && str[i] != c)
			i++;
		if (str[i] != '\0')
			i++;
	}
	return (ret);
}

static int		*get_size_words(char const *str, char c)
{
	int *ret;
	int i;
	int j;
	int k;

	if (!(ret = (int *)malloc(sizeof(int) * get_num_words(str, c))))
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			while (str[i] && str[i] != c)
			{
				i++;
				j++;
			}
			ret[k++] = j;
			j = 0;
		}
		i = (str[i] != '\0') ? i + 1 : i;
	}
	return (ret);
}

static char		**ft_cut_words(char const *str, char **tab_malloc, char c)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			while (str[i] && str[i] != c)
			{
				tab_malloc[j][k] = str[i];
				i++;
				k++;
			}
			tab_malloc[j][k] = '\0';
			j++;
			k = 0;
		}
		i = (str[i] != '\0') ? i + 1 : i;
	}
	tab_malloc[j] = NULL;
	return (tab_malloc);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		*size_words;
	int		num_words;
	char	**ret;

	if (s)
	{
		size_words = get_size_words(s, c);
		num_words = get_num_words(s, c);
		i = 0;
		if (!(ret = malloc(sizeof(char**) * num_words + 1)))
			return (NULL);
		while (i < num_words)
		{
			if (!(ret[i] = (char *)malloc(sizeof(char) * size_words[i] + 1)))
				return (NULL);
			i++;
		}
		free(size_words);
	}
	else
		return (NULL);
	return (ft_cut_words(s, ret, c));
}
