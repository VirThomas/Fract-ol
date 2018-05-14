/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 14:43:51 by thabdoul          #+#    #+#             */
/*   Updated: 2017/04/19 12:35:40 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	int		i;
	int		len;

	if (s)
	{
		len = ft_strlen(s);
		i = 0;
		while (i < len)
		{
			s[i] = '\0';
			i++;
		}
	}
}