/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 12:35:42 by thabdoul          #+#    #+#             */
/*   Updated: 2017/04/19 12:42:52 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*part;
	size_t	i;

	i = 0;
	part = NULL;
	if (s)
	{
		if (!(part = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (i < len)
		{
			part[i] = s[start];
			i++;
			start++;
		}
		part[i] = '\0';
	}
	return (part);
}
