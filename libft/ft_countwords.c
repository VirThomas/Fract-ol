/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 11:42:20 by thabdoul          #+#    #+#             */
/*   Updated: 2017/06/14 15:14:40 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countwords(char *str, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (!(str[i] == c))
		count++;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if ((str[i - 1] == c) && (str[i] != c))
		{
			i++;
			count++;
		}
		i++;
	}
	return (count);
}
