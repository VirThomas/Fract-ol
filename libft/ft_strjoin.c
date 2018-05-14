/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 14:28:51 by thabdoul          #+#    #+#             */
/*   Updated: 2017/04/19 12:46:14 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;
	size_t	maxilen;
	size_t	i;
	size_t	j;

	j = 0;
	i = -1;
	if (s1 && s2)
	{
		maxilen = ft_strlen((char*)s1) + ft_strlen((char*)s2) + 1;
		if (!(fresh = (char*)malloc(sizeof(char) * maxilen)))
			return (NULL);
		while (s1[++i])
			fresh[i] = s1[i];
		while (s2[j])
			fresh[i++] = s2[j++];
		fresh[maxilen - 1] = '\0';
		return (fresh);
	}
	return (NULL);
}
