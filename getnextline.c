/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnextline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 20:40:37 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/23 21:46:07 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getnextline.h"

char	*ft_buf_to_something(int fd)
{
	//static int		i;
	char			*str;
	char			*new_str;
	
	str = ft_memalloc(BUFF_SIZE);
	new_str = ft_memalloc(BUFF_SIZE + 1);
	while (read(fd, str, BUFF_SIZE / BUFF_SIZE) > 0)
		new_str = ft_strjoin(new_str, str);
	return (new_str);
}


int		getnextline(const int fd, char **line)
{
	char	*new_str;
	static int		i;
	int		a;
	int		j;
	static int		u;

	new_str = ft_buf_to_something(fd);
	while (new_str[i] != '\n')
		i++;
	ft_strcpy(line[j], new_str);
	if (line[j][ft_strlen(line[i])] == '\n')
	{
		i++;
		return (1);
	}
	if (line[j][a] == '\0')
		return (0);
	else
		return (-1);
}

int		main(int ac, char **av)
{
	(void)ac;
	int		fd;
	char	**line;
	int		i;

	i = 0;
	if (!(line = (char **)malloc(sizeof(char *) * 6500)))
		return (0);
	if (!(*line = (char *)malloc(sizeof(char) * 6500)))
		return (0);
	fd = open(av[1], O_RDONLY);
	//ft_buf_to_something(fd);
	//line = ft_strsplit(ft_buf_to_something(fd), '\n');
	if (getnextline(fd, line) == 1)
	{
		write(1, line[i], ft_strlen(line[i]));
		write(1, "\n", 1);
		i++;
	}
	if (getnextline(fd, line) == 0)
		return (0);
	return (0);
}
