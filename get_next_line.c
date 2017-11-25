/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 14:53:45 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/25 21:52:32 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_check_eol(char *buf)
{
	int		j;

	j = 0;
	write(1, "u", 1);
	while (buf[j] != EOL && buf[j])
		j++;
	if (buf[j] == EOL)
	{
		buf[j] = '\0';
		return (j);
	}
	return (-1);
}

int		ft_check_buff(char **buf, char *stock, char **line)
{
	int		endline;

	//if (*buf == NULL)
	//*buf = ft_memmove(*buf, stock, ft_strlen(stock));
	*buf = ft_strdup(stock);
	*buf = ft_strjoin(*buf, stock);
	bzero(stock, BUFF_SIZE);
	endline = ft_check_eol(*buf);
	//printf("%d", endline);
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
	int			check_buff;


	stock = ft_memalloc(BUFF_SIZE + 1);
	while (read(fd, stock, BUFF_SIZE) > 0)
	{
		check_buff = ft_check_buff(&buf[fd], stock, line);
		write(1, "v", 1);
		free(stock);
		if (check_buff == 1)
			return (1);
		stock = ft_memalloc(BUFF_SIZE + 1);
	}
	if (check_buff == ft_check_buff(&buf[fd], stock, line))
		return (0);
	return (-1);
}

int		main(int ac, char **av)
{
	int		fd;
	char	*line;
	(void)ac;
	fd = open(av[1], O_RDONLY);

	write(1, "o", 1);
	while (get_next_line(fd, &line) == 1)
	{
		ft_putendl(line);
		free(line);
	}
	/*if (get_next_line(fd, &line) == 0)
	{
		ft_putendl(line);
		free(line);
	}*/
	return (0);
}
