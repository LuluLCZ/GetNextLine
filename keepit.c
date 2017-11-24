/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnextline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llacaze <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 20:40:37 by llacaze           #+#    #+#             */
/*   Updated: 2017/11/24 21:49:44 by llacaze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_getnextline.h"

char	*malloc_again(char *str, size_t size)
{
	size_t		i;
	char		*new_str;
	size_t		j;
	size_t		k;

	k = -1;
	j = -1;
	i = ft_strlen(str);
	if (!(new_str = (char *)malloc(sizeof(char) * (i + size + 1))))
		return (NULL);
	while (str[++k] != '\0')
		new_str[++j] = str[k];
	while (j < i + size)
	{
		new_str[j] = '\0';
		j++;
	}
	//free(str);
	new_str[j] = '\0';
	return (new_str);
}

char	*ft_buf_to(int fd)
{
	//static char		*new_str[2147483648];
	char			buf[BUFF_SIZE];
	char			*new_str;

	if(!(new_str = (char *)malloc(sizeof(char) * BUFF_SIZE)))
		return (NULL);
	while (read(fd, buf, BUFF_SIZE) > 0)
	{
		new_str = ft_strjoin(new_str, buf);
		//str = malloc_again(str, BUFF_SIZE);
	}
	return (new_str);
}
/*
char	**ft_buf_to_something(int fd)
{
	int		i;
	int		k;
	int		l;
//	char	buf;
	char			*str;
	static char		*new_str[INT_MAX];
	char buf[BUFF_SIZE + 1];

	o = 0;
	k = 0;
	while (read(fd, buf, BUFF_SIZE) > 0)
	{
		i = -1;
		l = -1;
		if (!(new_str[fd] = (char *)malloc(sizeof(char) * (INT_MAX))))
			return (NULL);
		while (str[++i] != '\0')
		{
			//if (reaad <= 0)
			//	break;
			if (str[i] == '\n')
			{
				k++;
				l = -1;
			}
			new_str[k][++l] = str[i];
		}
		k++;
	}
	i = -1;
	while (new_str[++i])
		printf("%s", new_str[i]);
	return (new_str);
}*/

/*
char	*ft_check_nl(char **check)
{
	int		i;
	int		j;
	int		k;
	int		l;
	char	**line;

	k = -1;
	l = -1;
	i = -1;
	j = -1;
	while (*check[i++] != '\n')
	{
		*line[j++] = *check[i];
	}
	line++;

}*/
/*
int		geti_next_line(const int fd, char **line)
{
	char	*new_str;
	

	while (new_str[i] != '\n')
		i++;
	ft_strcpy(line[j], new_str)
	if (line[j][ft_strlen(line[i])] == '\n')
	{
		i++;
		return (1);
	}
	if (line[j][a] == '\0')
		return (0);
	else
		return (-1);
}*/

int		main(int ac, char **av)
{
	(void)ac;
	int		fd;
	char	*line;
	int		i;
//	char *new_str;

	i = 0;
	//if (!(line = (char **)malloc(sizeof(char *) * 6500)))
	//	return (0);
	//if (!(*line = (char *)malloc(sizeof(char) * 6500)))
	//	return (0);
	fd = open(av[1], O_RDONLY);
	line = ft_buf_to(fd);
	printf("%s", line);
	//ft_buf_to_something(fd);
	//line = ft_strsplit(ft_buf_to_something(fd), '\n');
	//if (getnextline(fd, line) == 1)
	//{
	//	write(1, line[i], ft_strlen(line[i]));
	//	write(1, "\n", 1);
	//	i++;
	//}
	//if (getnextline(fd, line) == 0)
	//	return (0);
	return (0);
}
