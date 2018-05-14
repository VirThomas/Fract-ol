/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 15:20:09 by thabdoul          #+#    #+#             */
/*   Updated: 2017/06/14 15:45:39 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_nbword(char *str)
{
	int		nb;
	int		new;

	nb = 0;
	new = 1;
	while (*str)
	{
		if (*str == ' ')
			new = 1;
		else if (new)
		{
			new = 0;
			nb++;
		}
		str++;
	}
	return (nb);
}
