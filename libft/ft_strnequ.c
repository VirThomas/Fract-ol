/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 16:08:12 by thabdoul          #+#    #+#             */
/*   Updated: 2017/04/19 12:42:25 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int		i;

	i = 0;
	if (s1 && s2)
	{
		if (n < 1)
			return (1);
		if (s1[i] != s2[i])
			return (0);
		while (s1[i] == s2[i] && s1[i] && s2[i] && n > 1)
		{
			i++;
			n--;
			if (s1[i] != s2[i])
				return (0);
		}
		return (1);
	}
	return (-1);
}
