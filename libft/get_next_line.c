/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabdoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 20:21:07 by thabdoul          #+#    #+#             */
/*   Updated: 2017/05/22 12:55:09 by thabdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	readln(int const fd, char **stock)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	char	*tmp;

	ret = 0;
	while ((!ft_strchr(*stock, '\n')))
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) <= 0)
			return (ret);
		buf[ret] = '\0';
		tmp = ft_strjoin(*stock, buf);
		ft_memdel((void**)stock);
		*stock = ft_strdup(tmp);
		ft_memdel((void**)&tmp);
	}
	return (OK);
}

static char	*getln(char *stock, char **line)
{
	char	*tmp;

	if (stock && (tmp = ft_strchr(stock, '\n')))
	{
		*line = ft_strsub(stock, 0, (ft_strlen(stock) - ft_strlen(tmp)));
		tmp = ft_strdup(tmp + 1);
		ft_strdel(&stock);
		return (tmp);
	}
	else
	{
		*line = ft_strdup(stock);
		ft_strclr(stock);
	}
	return (stock);
}

static char	*ft_lstfind(int fd, t_list **head)
{
	t_list	*curent;

	if (!(*head))
	{
		*head = ft_memalloc(sizeof(t_list));
		(*head)->content_size = fd;
	}
	else
	{
		curent = *head;
		while (curent != NULL && curent->content_size != (size_t)fd)
			curent = curent->next;
		if (curent == NULL)
		{
			curent = ft_memalloc(sizeof(t_list));
			curent->content_size = fd;
			curent->next = *head;
			*head = curent;
			return (NULL);
		}
		return (curent->content);
	}
	return ((*head)->content);
}

static void	ft_lstupdate(int fd, char *stock, t_list **head)
{
	t_list	*curent;

	curent = *head;
	while (curent->content_size != (size_t)fd)
		curent = curent->next;
	curent->content = ft_strdup(stock);
}

int			get_next_line(int const fd, char **line)
{
	char			*stock;
	int				ret;
	static t_list	*head = NULL;

	stock = ft_lstfind(fd, &head);
	if (!(line))
		return (ERROR);
	if (!stock)
		stock = ft_strnew(0);
	if ((ret = readln(fd, &stock)) == ERROR)
		return (ERROR);
	stock = getln(stock, line);
	ft_lstupdate(fd, stock, &head);
	if ((!ret && !ft_strlen(stock) && !ft_strlen(*line)))
		return (END);
	else
		return (OK);
}
