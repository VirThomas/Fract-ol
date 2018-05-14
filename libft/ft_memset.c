/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 10:28:33 by thabdoul          #+#    #+#             */
/*   Updated: 2017/04/12 15:28:02 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	int				i;
	unsigned char	*tab;

	tab = (unsigned char*)b;
	i = 0;
	while (n > 0)
	{
		tab[i] = (unsigned char)c;
		i++;
		n--;
	}
	return ((void*)b);
}
