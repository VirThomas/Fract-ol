/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 11:55:20 by thabdoul          #+#    #+#             */
/*   Updated: 2017/04/13 12:24:58 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	if (c == '\0')
		return (s + i);
	if ((size_t)i == ft_strlen(s))
		return (NULL);
	else
		return (s + i);
}
