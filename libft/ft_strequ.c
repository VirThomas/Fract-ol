/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 16:01:40 by thabdoul          #+#    #+#             */
/*   Updated: 2017/04/19 12:41:34 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int		i;

	i = 0;
	if (s1 && s2)
	{
		if (s1[i] != s2[i])
			return (0);
		while (s1[i] == s2[i] && s1[i] && s2[i])
		{
			i++;
			if (s1[i] != s2[i])
				return (0);
		}
		return (1);
	}
	return (-1);
}
