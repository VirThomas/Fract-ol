/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 15:07:53 by thabdoul          #+#    #+#             */
/*   Updated: 2017/04/19 12:39:40 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			fresh[i] = f(i, s[i]);
			i++;
		}
		fresh[len] = '\0';
	}
	return (fresh);
}
