/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 14:53:45 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/25 16:00:56 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_check_eol(char *buf)
{
	int		j;

	j = 0;
	write(1, "v", 1);
	while (buf[j] != EOL && buf[j])
		j++;
	if (buf[j] == EOL)
	{
		buf[j] = '\0';
		return (j);
	}
	return (-1);
}

int		ft_check_buff(char **buf, char **stock, char **line)
{
	int		endline;

	if (*buf == NULL)
		*buf = ft_strdup(*stock);
	*buf = ft_strjoin(*buf, *stock);
	bzero(stock, BUFF_SIZE + 1);
	endline = ft_check_eol(*buf);
	if (endline > -1)
	{
		*line = ft_strdup(*buf);
		*buf = ft_strdup(*buf + endline + 1);
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char	*buf[217483648];
	char		*stock;
	int			reead;

	stock = ft_memalloc(BUFF_SIZE + 1);
	reead = read(fd, stock, BUFF_SIZE);
	while (reead > 0)
	{
		if (ft_check_buff(&buf[fd], &stock, line) == 1)
			return (1);
		reead = read(fd, stock, BUFF_SIZE);
	}
	return (0);
}

int		main(int ac, char **av)
{
	int		fd;
	char	*line;
	(void)ac;
	fd = open(av[1], O_RDONLY);

	write(1, "v", 1);
	if (get_next_line(fd, &line) == 1)
	{
		ft_putendl(line);
		free(line);
	}
	return (0);
}
