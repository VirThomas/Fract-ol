/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 13:53:04 by thabdoul          #+#    #+#             */
/*   Updated: 2017/04/12 14:48:05 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strncat(char *s1, char *s2, size_t n)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s1);
	while (s2[i] != '\0' && n > 0)
	{
		s1[len] = s2[i];
		i++;
		len++;
		n--;
	}
	s1[len] = '\0';
	return (s1);
}
