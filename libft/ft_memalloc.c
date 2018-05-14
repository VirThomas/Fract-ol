/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 12:42:49 by thabdoul          #+#    #+#             */
/*   Updated: 2017/04/13 18:26:35 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void			*coucou;
	char			*koukou;
	size_t			i;

	i = 0;
	if (!(coucou = malloc(sizeof(char) * size)))
		return (NULL);
	koukou = (char*)coucou;
	while (i < size)
	{
		koukou[i] = '\0';
		i++;
	}
	coucou = (void*)koukou;
	return (coucou);
}
