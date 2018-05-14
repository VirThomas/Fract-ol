/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 13:31:06 by thabdoul          #+#    #+#             */
/*   Updated: 2017/04/19 14:51:49 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_error(void)
{
	char	*test;

	test = (char*)malloc(1);
	if (!test)
		return (NULL);
	test[0] = '\0';
	return (test);
}

char			*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	char	*plop;
	size_t	len;
	size_t	len2;

	if (!s)
		return (NULL);
	len2 = ft_strlen((char*)s);
	len = ft_strlen((char*)s) - 1;
	i = 0;
	j = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && (s[i] != '\0'))
		i++;
	while ((s[len] == ' ' || s[len] == '\n'
				|| s[len] == '\t') && s[len] != '\0')
		len--;
	if (i == len2)
		return (ft_error());
	if (!(plop = (char*)malloc(sizeof(char) * len - i + 2)))
		return (NULL);
	while (i < len + 1 && i != len2)
		plop[j++] = s[i++];
	plop[j] = '\0';
	return (plop);
}
