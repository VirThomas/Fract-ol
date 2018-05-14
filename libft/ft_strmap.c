/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 14:59:54 by thabdoul          #+#    #+#             */
/*   Updated: 2017/04/19 12:38:27 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fresh;
	size_t	i;
	size_t	len;

	fresh = NULL;
	if (s && f)
	{
		i = 0;
		len = ft_strlen((char*)s);
		if (!(fresh = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (i < len)
		{
			fresh[i] = f(s[i]);
			i++;
		}
		fresh[len] = '\0';
	}
	return (fresh);
}
