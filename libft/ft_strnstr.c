/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 15:48:15 by thabdoul          #+#    #+#             */
/*   Updated: 2017/04/18 17:03:11 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str, char *to_find, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	tmp;

	i = 0;
	j = 0;
	if (!*to_find)
		return (str);
	while (str[i] && i < len)
	{
		if (str[i] != to_find[j])
		{
			j = 0;
			i++;
		}
		else
		{
			tmp = i;
			while (i < len && str[i] == to_find[j] && str[i++] && to_find[j++])
				if (j == ft_strlen(to_find))
					return (&str[i - j]);
			i = tmp + 1;
		}
	}
	return (NULL);
}
