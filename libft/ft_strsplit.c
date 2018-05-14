/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 15:00:06 by thabdoul          #+#    #+#             */
/*   Updated: 2017/06/14 15:19:49 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words_count(char const *str, char c)
{
	int			i;
	static int	count;

	i = 0;
	count = 0;
	if (!(str[i] == c))
		count++;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if ((str[i - 1] == c) && (str[i] != c))
		{
			i++;
			count++;
		}
		i++;
	}
	return (count);
}

static char	**ft_coucou(char const *str, char c, char **tab, int k)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		j = i;
		while (str[i] == c && str[i++])
			j++;
		while (str[i] && str[i] != c)
			i++;
		if (j >= i)
			break ;
		if (!(tab[k] = (char*)malloc(sizeof(char) * (i - j + 1))))
			return (NULL);
		ft_strncpyforsplit(tab[k++], (char*)str + j, i - j);
	}
	tab[k] = NULL;
	return (tab);
}

char		**ft_strsplit(char const *str, char c)
{
	char	**tab;
	int		k;

	if (str)
	{
		k = 0;
		tab = (char **)malloc(sizeof(char*) * (ft_words_count(str, c) + 1));
		if (!tab)
			return (NULL);
		tab = ft_coucou(str, c, tab, k);
		return (tab);
	}
	return (NULL);
}
