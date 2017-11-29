/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 14:53:45 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/29 11:56:33 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_check_eol(char *buf)
{
	int		j;

	j = 0;
	if (buf != NULL)
	{
		while (buf[j] != EOL && buf[j])
			j++;
		if (buf[j] == EOL)
		{
			buf[j] = '\0';
			return (j);
		}
	}
	return (-1);
}

int		ft_check_buf(char **buf, char *stock, char **line)
{
	char	*tmp;
	int		endline;

	tmp = *buf;
	*buf = ft_strjoin(*buf, stock);
	bzero(stock, BUFF_SIZE);
	endline = ft_check_eol(*buf);
	free(tmp);
	if (endline > -1)
	{
		*line = ft_strdup(*buf);
		tmp = *buf;
		*buf = ft_strdup(*buf + endline + 1);
		free(tmp);
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char	*buf[217483648];
	char		*stock;
	size_t		check_buf;
	int			ret;

	stock = ft_memalloc(BUFF_SIZE + 1);
	if (fd < 0 || BUFF_SIZE <= 0 || !line || (ret = read(fd, stock, 0)) < 0)
		return (-1);
	while ((ret = read(fd, stock, BUFF_SIZE)) > 0)
	{
		check_buf = ft_check_buf(&buf[fd], stock, line);
		free(stock);
		if (check_buf == 1)
			return (1);
		stock = ft_memalloc(BUFF_SIZE);
	}
	if (ft_check_buf(&buf[fd], stock, line) == 1)
		return (1);
	else if (ft_check_buf(&buf[fd], stock, line) == 0 && ft_strlen(buf[fd]) > 0)
	{
		*line = ft_strdup(buf[fd]);
		ft_strdel(&buf[fd]);
		free(*buf);
		return (1);
	}
	return (0);
}
/*
int		main(int ac, char **av)
{
	int		fd;
	char	*line;

	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		ft_putendl(line);
		free(line);
	}
	return (0);
}*/
