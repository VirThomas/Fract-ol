/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 10:08:59 by thabdoul          #+#    #+#             */
/*   Updated: 2017/04/18 13:48:34 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_len(int n)
{
	int len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char		*create_str(int len, int n, int neg, char *str)
{
	while (len >= 0)
	{
		str[len] = (n % 10) + 48;
		n /= 10;
		len--;
	}
	if (neg < 0)
		str[0] = '-';
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		neg;

	neg = n;
	len = (int)get_len(n);
	str = (char *)malloc(sizeof(*str) * (len + 1));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!str)
		return (NULL);
	str[len] = '\0';
	len--;
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (n < 0)
		n = -n;
	return (char*)(create_str(len, n, neg, str));
}
