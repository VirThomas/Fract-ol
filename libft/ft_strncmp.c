/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 21:34:38 by thabdoul          #+#    #+#             */
/*   Updated: 2017/04/17 15:24:01 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0 && (unsigned char)*s1 == (unsigned char)*s2)
	{
		if (*s1 == '\0' || *s2 == '\0')
			return (0);
		s1++;
		s2++;
		n--;
	}
	if (!n)
		return ((unsigned char)*--s1 - (unsigned char)*--s2);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
