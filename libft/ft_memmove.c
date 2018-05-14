/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:15:41 by thabdoul          #+#    #+#             */
/*   Updated: 2017/04/19 11:47:30 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*source;

	dest = (unsigned char*)dst;
	source = (unsigned char*)src;
	i = 0;
	if (len == 0)
		return (dst);
	if (dst <= src)
	{
		while (++i < len)
			*dest++ = *source++;
	}
	if (dst > src)
	{
		len--;
		while (len > 0)
		{
			dest[len] = source[len];
			len--;
		}
	}
	dest[0] = source[0];
	return (dst);
}
